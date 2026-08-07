class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        ranges::sort(candidates);
        int n = candidates.size();
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i, int sum) {
            if (sum > target) return;
            if (sum == target) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                path.emplace_back(candidates[j]);
                dfs(j, sum + candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};