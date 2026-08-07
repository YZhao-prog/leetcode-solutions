class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        ranges::sort(candidates);
        auto dfs = [&](this auto&& dfs, int i, int sum) {
            if (sum > target) return;
            if (sum == target) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (j > i && candidates[j] == candidates[j - 1]) continue;
                path.emplace_back(candidates[j]);
                dfs(j + 1, sum + candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};