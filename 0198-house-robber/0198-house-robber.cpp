class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        int n = nums.size();
        int f0 = 0, f1 = nums[0];
        for (int i = 1; i < n; i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};