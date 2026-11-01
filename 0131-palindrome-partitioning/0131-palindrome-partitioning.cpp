class Solution {
public:
    bool isPalindrome(const string& s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n = s.size();
        vector<string> path;
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.push_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                string str = s.substr(i, j - i + 1);
                if (isPalindrome(str)) {
                    path.push_back(str);
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};