class Solution {
private:
    int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> vis;
public:
    int dfs(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        int size = 1;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
            if (grid[nx][ny] && !vis[nx][ny]) {
                size += dfs(grid, nx, ny);
            }
        }
        return size;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis = vector(n, vector(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};