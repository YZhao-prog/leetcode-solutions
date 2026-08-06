class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;
        auto isPalindrome = [](string_view str, int i, int j) -> bool {
            while (i < j) {
                if (str[i++] != str[j--]) {
                    return false;
                }
            }
            return true;
        };
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};