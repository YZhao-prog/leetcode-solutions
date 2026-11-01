class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        auto dfs = [&](this auto&& dfs, int i, int left, int right) {
            if (i == 2 * n) {
                ans.emplace_back(path);
                return;
            }
            if (left < n)  {
                path.push_back('(');
                dfs(i + 1, left + 1, right);
                path.pop_back();
            }
            if (right < left) {
                path.push_back(')');
                dfs(i + 1, left, right + 1);
                path.pop_back();
            }
        };
        dfs(0, 0, 0);
        return ans;
    }
};