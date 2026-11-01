class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0) {
                return 0;
            }
            if (memo[i] != -1) {
                return memo[i];
            }
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            memo[i] = res;
            return res;
        };
        return dfs(n - 1);
    }
};