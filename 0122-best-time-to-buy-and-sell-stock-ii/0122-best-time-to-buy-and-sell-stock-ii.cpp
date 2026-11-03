class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] and dp[i][1]
        // dp[i][0] = max(dp[i - 1][1] + price, dp[i - 1][0])
        // dp[i][1] = max(dp[i - 1][0] - prince, dp[i - 1][1])
        int n = prices.size();
        auto dp = vector(n + 1, vector(2, 0));
        dp[1][0] = 0, dp[1][1] = -prices[0];
        for (int i = 2; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};