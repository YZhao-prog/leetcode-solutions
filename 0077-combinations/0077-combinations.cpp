class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i) {
            if (path.size() == k) {
                ans.emplace_back(path);
                return;
            }
            // [x. x + 1, ...n] n - x + 1 >= k - path.size()
            for (int j = i; j <= n + 1 - k + path.size(); j++) {
                path.push_back(j);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};