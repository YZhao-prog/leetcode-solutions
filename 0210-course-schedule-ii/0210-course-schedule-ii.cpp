class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (auto y: edges[x]) {
                if (--d[y] == 0){
                    q.push(y);
                }
            }
        }
        if (ans.size() != numCourses) {
            return {};
        }
        return ans;
    }
};