class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> d(numCourses, 0);
        for (auto e: prerequisites) {
            edges[e[1]].push_back(e[0]);
            d[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (d[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            auto x = q.front();
            ++cnt;
            q.pop();
            for (auto y: edges[x]) {
                if (--d[y] == 0) {
                    q.push(y);
                }
            }
        }
        return cnt == numCourses;

    }
};