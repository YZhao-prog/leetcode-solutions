class Solution {
private:
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> minDis(n, vector(m, INT_MAX));
        minDis[entrance[0]][entrance[1]] = 0;
        q.emplace(entrance[0], entrance[1]);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (!(x == entrance[0] && y == entrance[1]) && (x == n - 1 || y == m - 1 || x == 0 || y == 0)) {
                return minDis[x][y];
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                if (minDis[nx][ny] == INT_MAX && maze[nx][ny] == '.') {
                    minDis[nx][ny] = minDis[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        return -1;
    }
};