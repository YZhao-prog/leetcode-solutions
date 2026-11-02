class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // p - (s - p) = target
        // p = (s + t) / 2
        int n = nums.size();
        int sum = reduce(nums.begin(), nums.end());
        int cap = (sum + target) / 2;
        if (sum + target < 0 || (sum + target) % 2 == 1) return 0;
        // dp[i][c] = dp[i - 1][c] if c < nums[i]
        // dp[i][c] = dp[i - 1][c] + dp[i][c - nums[i]]
        auto dp = vector(n + 1, vector(cap + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= cap; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][cap];
    }
};