class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        auto dp = vector(n + 1, vector(k + 1, vector(2, 0)));
        for (int j = 0; j <= k; j++) {
            dp[0][j][1] = INT_MIN / 2;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++){
                dp[i][j][0] = max(dp[i - 1][j][1] + prices[i - 1], dp[i - 1][j][0]);
                dp[i][j][1] = max(dp[i - 1][j - 1][0] - prices[i - 1], dp[i - 1][j][1]);
            }
        }
        return dp[n][k][0];
    }
};