#!/usr/bin/env python3
"""Regenerate the README's language and topic summary from the problem folders.

Topic tags come from LeetCode's public GraphQL API and are cached in
scripts/topics_cache.json, so a run only fetches problems it has not seen
before. If the API is unreachable, cached data is used and the run still
succeeds -- it just skips any problem that is both new and unfetchable.

Usage: python3 scripts/update_topics.py [--check]
  --check  exit 1 if README.md would change, without writing it
"""

import json
import os
import re
import sys
import time
import urllib.error
import urllib.request
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CACHE = os.path.join(ROOT, "scripts", "topics_cache.json")
README = os.path.join(ROOT, "README.md")

START = "<!-- AUTO-TOPICS:START -->"
END = "<!-- AUTO-TOPICS:END -->"

EXT_LANG = {".go": "Go", ".cpp": "C++", ".cc": "C++", ".c": "C",
            ".py": "Python", ".java": "Java", ".js": "JavaScript",
            ".ts": "TypeScript", ".rs": "Rust", ".kt": "Kotlin"}

QUERY = ("query q($t:String!){question(titleSlug:$t)"
         "{questionFrontendId difficulty topicTags{name}}}")

# LeetCode hands back a few tags that are noise in a summary table: "X 算法"
# and "Algorithm X" are the same tag in two languages, and Dancing Links is
# just how Algorithm X is implemented. All three are exact-cover backtracking
# and only ever appear on the sudoku solver, so fold them into Backtracking.
ALIASES = {
    "X 算法": "Backtracking",
    "Algorithm X": "Backtracking",
    "Dancing Links": "Backtracking",
}


def problem_dirs():
    return sorted(d for d in os.listdir(ROOT)
                  if re.match(r"^\d{4}-", d) and os.path.isdir(os.path.join(ROOT, d)))


def languages_in(d):
    langs = set()
    for f in os.listdir(os.path.join(ROOT, d)):
        ext = os.path.splitext(f)[1].lower()
        if ext in EXT_LANG:
            langs.add(EXT_LANG[ext])
    return langs


def load_cache():
    try:
        with open(CACHE) as fh:
            return json.load(fh)
    except (OSError, ValueError):
        return {}


def fetch(slug):
    body = json.dumps({"query": QUERY, "variables": {"t": slug}}).encode()
    req = urllib.request.Request(
        "https://leetcode.com/graphql", data=body, method="POST",
        headers={"Content-Type": "application/json",
                 "User-Agent": "Mozilla/5.0 (readme-topic-sync)"})
    with urllib.request.urlopen(req, timeout=20) as r:
        q = json.load(r)["data"]["question"]
    if not q:
        raise ValueError("no question data for " + slug)
    return {"difficulty": q["difficulty"],
            "topics": [t["name"] for t in q["topicTags"]]}


# LeetHub writes "undefined" into its own index when it cannot read a
# problem's difficulty. We already hold the real value, so patch those cells
# on every run -- LeetHub keeps reintroducing them as new problems sync.
LEETHUB_ROW = re.compile(
    r"^(\|\s*\[(\d{4}-[a-z0-9-]+)\]\([^)]*\)\s*\|\s*)undefined(\s*\|)\s*$", re.M)


def repair_leethub_difficulties(text, cache):
    fixed = [0]

    def sub(m):
        info = cache.get(m.group(2)[5:])
        if not info or not info.get("difficulty"):
            return m.group(0)
        fixed[0] += 1
        return f"{m.group(1)}{info['difficulty']}{m.group(3)}"

    return LEETHUB_ROW.sub(sub, text), fixed[0]


LEETHUB_START = "<!---LeetCode Topics Start-->"
LEETHUB_END = "<!---LeetCode Topics End-->"
PROBLEM_LINK = re.compile(r"\|\s*\[(\d{4}-[a-z0-9-]+)\]")


def fold_leethub_sections(text):
    """Drop LeetHub sections for aliased tags, e.g. the duplicated "X 算法"
    and "Algorithm X". A section is only removed once every problem in it is
    confirmed present under the tag it folds into, so nothing is lost."""
    if LEETHUB_START not in text or LEETHUB_END not in text:
        return text, []
    a = text.index(LEETHUB_START)
    b = text.index(LEETHUB_END)
    block, removed = text[a:b], []

    # Split into ("## Heading", body) chunks, keeping the block preamble.
    parts = re.split(r"(?m)^(## .+)$", block)
    preamble, sections = parts[0], list(zip(parts[1::2], parts[2::2]))
    members = {h[3:].strip(): set(PROBLEM_LINK.findall(body)) for h, body in sections}

    kept = []
    for heading, body in sections:
        name = heading[3:].strip()
        target = ALIASES.get(name)
        if target and target != name:
            if members.get(name, set()) <= members.get(target, set()):
                removed.append(name)
                continue
            print(f"  ! keeping '{name}': problems missing from '{target}'",
                  file=sys.stderr)
        kept.append((heading, body))

    if not removed:
        return text, []
    return text[:a] + preamble + "".join(h + b for h, b in kept) + text[b:], removed


def save_cache(cache):
    os.makedirs(os.path.dirname(CACHE), exist_ok=True)
    with open(CACHE, "w", encoding="utf-8") as fh:
        json.dump(cache, fh, indent=1, sort_keys=True)
        fh.write("\n")


def main():
    check_only = "--check" in sys.argv
    cache = load_cache()
    dirs = problem_dirs()

    missing = [d for d in dirs if d[5:] not in cache]
    if missing:
        print(f"fetching {len(missing)} new problem(s) from LeetCode...")
    fetched = 0
    for i, d in enumerate(missing):
        slug = d[5:]
        try:
            cache[slug] = fetch(slug)
            fetched += 1
            print(f"  + {slug}: {', '.join(cache[slug]['topics']) or '(no tags)'}")
        except (urllib.error.URLError, ValueError, KeyError, TimeoutError) as e:
            print(f"  ! {slug}: skipped ({e})", file=sys.stderr)
        if i < len(missing) - 1:
            time.sleep(1)  # be polite to the API

    # Persist newly fetched tags even when the table itself is unchanged,
    # otherwise those problems get re-fetched on every future run.
    if fetched and not check_only:
        save_cache(cache)

    # A problem carries several LeetCode tags and belongs under all of them,
    # so counts here overlap by design and deliberately do not sum to the total.
    by_topic = defaultdict(list)
    lang_totals = Counter()
    difficulty = Counter()
    untagged = []
    for d in dirs:
        slug = d[5:]
        langs = languages_in(d)
        for l in langs:
            lang_totals[l] += 1
        info = cache.get(slug)
        if not info or not info["topics"]:
            untagged.append(d)
            continue
        difficulty[info["difficulty"]] += 1
        # Alias first, then dedupe: a problem tagged both "Algorithm X" and
        # "Backtracking" must still count once under Backtracking.
        seen = set()
        for topic in info["topics"]:
            topic = ALIASES.get(topic, topic)
            if topic not in seen:
                seen.add(topic)
                by_topic[topic].append((d, langs))

    rows = sorted(by_topic.items(), key=lambda kv: (-len(kv[1]), kv[0]))
    summary = f"**{len(dirs)} problems solved**"
    if lang_totals:
        summary += " — " + ", ".join(f"{n} in {l}" for l, n in lang_totals.most_common())
    diff_order = [d for d in ("Easy", "Medium", "Hard") if difficulty[d]]
    if diff_order:
        summary += "  \n" + " · ".join(f"{difficulty[d]} {d}" for d in diff_order)

    lines = [START, "", summary, "",
             "| Topic | Problems | Languages |",
             "| --- | ---: | --- |"]
    for topic, entries in rows:
        langs = sorted({l for _, ls in entries for l in ls})
        lines.append(f"| {topic} | {len(entries)} | {', '.join(langs) or '—'} |")
    if untagged:
        lines.append(f"| _(untagged)_ | {len(untagged)} | — |")
    lines += ["",
              "<sub>Generated by `scripts/update_topics.py` from LeetCode's topic tags. "
              "A problem carries several tags, so the counts overlap and do not sum to the "
              "total.</sub>",
              "", END]
    block = "\n".join(lines)

    with open(README, encoding="utf-8") as fh:
        text = fh.read()
    if START in text and END in text:
        new = text[:text.index(START)] + block + text[text.index(END) + len(END):]
    else:
        print("markers not found in README.md", file=sys.stderr)
        return 1

    new, repaired = repair_leethub_difficulties(new, cache)
    if repaired:
        print(f"repaired {repaired} 'undefined' difficulty cell(s) in the LeetHub index")

    new, folded = fold_leethub_sections(new)
    if folded:
        print("folded LeetHub section(s) into their parent tag: " + ", ".join(folded))

    if new == text:
        print("README.md already up to date")
        return 0
    if check_only:
        print("README.md is out of date (run without --check to update)")
        return 1

    with open(README, "w", encoding="utf-8") as fh:
        fh.write(new)
    save_cache(cache)
    print(f"README.md updated ({len(dirs)} problems, {len(rows)} topics)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
