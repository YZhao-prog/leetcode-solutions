class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> on_path(n);
        auto dfs = [&](this auto& dfs, int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (on_path[j]) continue;
                path.emplace_back(nums[j]);
                on_path[j] = 1;
                dfs(i + 1);
                on_path[j] = 0;
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};