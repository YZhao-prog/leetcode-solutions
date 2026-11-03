class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] and dp[i][1]
        // dp[i][0] = max(dp[i - 1][1] + price, dp[i - 1][0])
        // dp[i][1] = max(dp[i - 1][0] - prince, dp[i - 1][1])
        int n = prices.size();
        auto dp = vector(n + 1, vector(2, 0));
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] - prices[i - 1], dp[i - 1][1]);
        }
        return dp[n][0];
    }
};