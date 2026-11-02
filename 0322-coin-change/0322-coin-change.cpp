class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int m = amount;
        // dp[i][j] = min(dp[i - 1][j], dp[i][j] - coins[i]] + 1)
        auto dp = vector(m + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = coins[i - 1]; j <= m; j++) {
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
            }
        }
        return dp[m] < INT_MAX / 2 ? dp[m] : -1;
    }
};