class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        auto dist = vector(n, INT_MAX / 2);
        dist[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            auto now = dist;
            for (auto e: flights) {
                int x = e[0], y = e[1], w = e[2];
                if (dist[y] > now[x] + w) {
                    dist[y] = now[x] + w;
                }
            }
        }
        return dist[dst] == INT_MAX / 2 ? -1 : dist[dst];
    }
};