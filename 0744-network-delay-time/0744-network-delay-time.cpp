class Solution {
private:
    vector<vector<pair<int, int>>> edges;
    vector<int> dist;
public:
    int dij(vector<vector<pair<int, int>>>& edges, vector<int>& dist, int k) {
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(dist[k], k);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dist[x]) continue;
            for (auto& [y, d]: edges[x]) {
                if (dist[y] > dx + d) {
                    dist[y] = dx + d;
                    pq.emplace(dist[y], y);
                }
            }
        }
        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans < INT_MAX ? ans : -1;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        edges.resize(n + 1);
        dist.resize(n + 1, INT_MAX);
        for (auto& e: times) {
            edges[e[0]].push_back({e[1], e[2]});
        }
        return dij(edges, dist, k);
    }
};