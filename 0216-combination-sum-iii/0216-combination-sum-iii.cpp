class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        auto dfs = [&](this auto&& dfs, int i) {
            if (sum > n) {
                return;
            }
            if (path.size() == k) {
                if (sum == n) {
                    ans.push_back(path);
                }
                return;
            }
            for (int j = i; j <= 9; j++) {
                path.push_back(j);
                sum += j;
                dfs(j + 1);
                sum -= j;
                path.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};