class Solution {
public:
    int strStr(string haystack, string needle) {
        string s = needle + "#" + haystack;
        int m = needle.size();
        vector<int> nxt(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            int len = nxt[i - 1];
            while (len && s[i] != s[len]) {
                len = nxt[len - 1];
            }
            if (s[i] == s[len]) {
                nxt[i] = len + 1;
                if (nxt[i] == m) {
                    return i - 2 * m;
                }
            }
        }
        return -1;
    }
};