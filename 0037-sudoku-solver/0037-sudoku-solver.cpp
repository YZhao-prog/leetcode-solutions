class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_map<int, int>> row;
        unordered_map<int, unordered_map<int, int>> col;
        unordered_map<int, unordered_map<int, unordered_map<int, int>>> grid;
        int n = board.size();
        for (int i = 0; i < n; i++) {
            int m = board[i].size();
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;
                int x = board[i][j] - '0';
                row[i][x] = 1;
                col[j][x] = 1;
                grid[i / 3][j / 3][x] = 1;
            }
        }
        auto dfs = [&](this auto&& dfs, int pos) -> bool {
            if (pos == 81) {
                return true;
            }
            int x = pos / 9, y = pos % 9;
            if (board[x][y] != '.') return dfs(pos + 1);
            for (int i = 1; i <= 9; i++) {
                if (row[x][i] || col[y][i] || grid[x / 3][y / 3][i]) {
                    continue;
                }
                row[x][i] = 1;
                col[y][i] = 1;
                grid[x / 3][y / 3][i] = 1;
                board[x][y] = i + '0';
                if (dfs(pos + 1)) return true;
                board[x][y] = '.';
                row[x][i] = 0;
                col[y][i] = 0;
                grid[x / 3][y / 3][i] = 0;
            }
            return false;
        };
        dfs(0);
    }
};