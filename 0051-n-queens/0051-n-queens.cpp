class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        vector<int> diag1(2*n, 0);
        vector<int> diag2(2*n, 0);
        vector<vector<string>> ans;
        vector<string> path;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!row[i] && !col[j] && !diag1[i + j] && !diag2[n + i - j]) {
                    string str(n, '.');
                    str[j] = 'Q';
                    path.emplace_back(str);
                    row[i] = 1;
                    col[j] = 1;
                    diag1[i + j] = 1;
                    diag2[n + i - j] = 1;
                    dfs(i + 1);
                    path.pop_back();
                    row[i] = 0;
                    col[j] = 0;
                    diag1[i + j] = 0;
                    diag2[n + i - j] = 0;
                }
            }
        };
        dfs(0);
        return ans;
    }
};