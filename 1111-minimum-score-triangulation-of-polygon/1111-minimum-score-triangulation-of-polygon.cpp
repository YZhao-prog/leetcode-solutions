class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // dp[i][j] = dp[i][k] + dp[k][j] + v[i] * v[j] * v[k];
        int n = values.size();
        auto dp = vector(n, vector(n, 0));
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};