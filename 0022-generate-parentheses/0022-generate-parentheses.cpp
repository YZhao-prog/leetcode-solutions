class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        auto dfs = [&](this auto&& dfs, int i, int open) {
            if (path.size() == 2 * n) {
                ans.emplace_back(path);
                return;
            }
            if (open < n)  {
                path.push_back('(');
                dfs(i + 1, open + 1);
                path.pop_back();
            }
            if (i - open < open) {
                path.push_back(')');
                dfs(i + 1, open);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};