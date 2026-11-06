class Solution {
private:
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> vis;
public:
    void bfs(const vector<vector<char>>& grid, const int& x, const int& y) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front();
            cout << x << y << " ";
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if (vis[nx][ny] || grid[nx][ny] == '0') continue;
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[m].size();
        vis = vector(n, vector(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};