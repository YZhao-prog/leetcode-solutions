class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = nums.size();
        vector<int> used(n);
        ranges::sort(nums);
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (used[j] || (j != 0 && nums[j] == nums[j - 1] && !used[j - 1])) continue;
                path.emplace_back(nums[j]);
                used[j] = true;
                dfs(i + 1);
                used[j] = false;
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};