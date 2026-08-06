# LeetCode Solutions

My LeetCode solutions, written in **Go** and **C++**, focused on strengthening data structures
and algorithms skills for coding interviews.

## 📌 About

Submissions are pushed automatically from LeetCode by
[LeetHub](https://github.com/QasimWani/LeetHub), so each commit message records the runtime and
memory of the accepted run, and the topic index at the bottom of this file is generated rather
than hand-written.

## 🛠 Languages

61 problems solved so far, across two languages:

- **Go** — 58 solutions; the language used for the linked list, tree/BST and binary search work
- **C++** — 5 solutions, all on backtracking problems (0017, 0037, 0077, 0078, 0131)

Problems 0017 and 0078 have solutions in both languages; 0037, 0077 and 0131 are C++ only.

## 📂 Structure

One directory per problem, named `<number>-<problem-slug>`, holding the problem statement plus
a solution file per language:

```
0206-reverse-linked-list/
├── 0206-reverse-linked-list.go    # accepted solution
└── README.md                      # the LeetCode problem statement

0078-subsets/
├── 0078-subsets.go                # accepted Go solution
├── 0078-subsets.cpp               # accepted C++ solution
└── README.md
```

## 🎯 Topics Covered

| Topic | Problems | Languages |
| --- | ---: | --- |
| Binary Trees & Binary Search Trees | 30 | Go |
| Linked Lists | 19 | Go |
| Binary Search | 7 | Go |
| Recursion & Backtracking | 5 | C++, Go |

The auto-generated index below covers only problems synced since LeetHub topic tracking was
enabled, so it is not yet a complete listing.

## 🚀 Usage

These files are raw LeetCode submissions rather than standalone programs, so neither
`go run <file>.go` nor `g++ <file>.cpp` will work on them directly. The Go files carry no
`package` clause and no `main` (and there is no `go.mod`); the C++ files are a bare
`class Solution` with no `#include` directives and no `main`. To try one locally, paste it into
a scratch file with the missing scaffolding.

Go:

```go
package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

// ... paste the solution function here ...

func main() {
	fmt.Println(reverseList(&ListNode{Val: 1, Next: &ListNode{Val: 2}}))
}
```

```bash
go run main.go
```

C++:

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// ... paste the class Solution here ...

int main() {
	Solution s;
	for (const string& r : s.letterCombinations("23")) cout << r << ' ';
	cout << endl;
}
```

These solutions use C++23 features such as `constexpr std::string` and deducing `this`, matching
what LeetCode compiles against, so an older `-std` will not build them:

```bash
g++ -std=c++2b main.cpp -o main && ./main
```

<!---LeetCode Topics Start-->
# LeetCode Topics
## Hash Table
| Problem Name | Difficulty |
| ------- | ------- |
| [0017-letter-combinations-of-a-phone-number](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0017-letter-combinations-of-a-phone-number/) | Medium |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
## String
| Problem Name | Difficulty |
| ------- | ------- |
| [0017-letter-combinations-of-a-phone-number](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0017-letter-combinations-of-a-phone-number/) | Medium |
| [0131-palindrome-partitioning](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0131-palindrome-partitioning/) | undefined |
## Backtracking
| Problem Name | Difficulty |
| ------- | ------- |
| [0017-letter-combinations-of-a-phone-number](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0017-letter-combinations-of-a-phone-number/) | Medium |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
| [0077-combinations](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0077-combinations/) | undefined |
| [0078-subsets](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0078-subsets/) | undefined |
| [0131-palindrome-partitioning](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0131-palindrome-partitioning/) | undefined |
## Bit Manipulation
| Problem Name | Difficulty |
| ------- | ------- |
| [0078-subsets](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0078-subsets/) | undefined |
## Array
| Problem Name | Difficulty |
| ------- | ------- |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
| [0078-subsets](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0078-subsets/) | undefined |
## Dynamic Programming
| Problem Name | Difficulty |
| ------- | ------- |
| [0131-palindrome-partitioning](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0131-palindrome-partitioning/) | undefined |
## Matrix
| Problem Name | Difficulty |
| ------- | ------- |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
## X 算法
| Problem Name | Difficulty |
| ------- | ------- |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
## Dancing Links
| Problem Name | Difficulty |
| ------- | ------- |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | undefined |
## Algorithm X
| Problem Name | Difficulty |
| ------- | ------- |
| [0037-sudoku-solver](https://github.com/YZhao-prog/leetcode-solutions/tree/main/0037-sudoku-solver/) | Hard |
<!---LeetCode Topics End-->