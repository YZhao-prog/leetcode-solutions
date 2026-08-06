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
            for (int j = i; j <= n; j++) {
                path.push_back(j);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};