class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        vector<int> used(n);
        ranges::sort(candidates);
        auto dfs = [&](this auto&& dfs, int i, int sum) {
            if (sum > target) return;
            if (sum == target) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j < n; j++) {
                if (j > 0 && candidates[j] == candidates[j - 1] && !used[j - 1]) continue;
                path.emplace_back(candidates[j]);
                used[j] = true;
                dfs(j + 1, sum + candidates[j]);
                used[j] = false;
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};