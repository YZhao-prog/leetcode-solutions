class Solution {
private:
    int d[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> areas;
        auto dfs = [&](this auto&& dfs, int x, int y) -> int {
            int size = 1;
            grid[x][y] = areas.size() + 2; // id
            for (int k = 0; k < 4; k++) {
                int nx = x + d[k][0], ny = y + d[k][1];
                if (nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
                if (grid[nx][ny] == 1) {
                    size += dfs(nx, ny);
                }
            }
            return size;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    areas.push_back(dfs(i, j));
                }
            }
        }

        if (areas.size() == 0) return 1;

        int ans = 0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                s.clear();
                int sz = 1;
                for (int k = 0; k < 4; k++) {
                    int ni = i + d[k][0], nj = j + d[k][1];
                    if (ni < 0 || ni > n - 1 || nj < 0 || nj > n - 1) continue;
                    if (!s.count(grid[ni][nj]) && grid[ni][nj]) {
                        s.insert(grid[ni][nj]);
                        sz += areas[grid[ni][nj] - 2];
                    }
                }
                ans = max(ans, sz);
            }
        }
        return ans == 0 ? n * n : ans;
    }
};