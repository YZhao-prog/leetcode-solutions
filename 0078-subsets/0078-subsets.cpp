class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            ans.emplace_back(path);
            for (int j = i; j < n; j++) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};