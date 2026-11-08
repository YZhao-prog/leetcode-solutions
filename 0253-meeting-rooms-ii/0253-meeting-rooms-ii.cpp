class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 0  5  10 15 20 30
        // +1 +1 -1 +1 -1 -1
        vector<pair<int, int>> arr;
        for (auto& e: intervals) {
            arr.push_back({e[0], 1});
            arr.push_back({e[1], -1});
        }
        sort(arr.begin(), arr.end());
        int tot = 0;
        int ans = 0;
        for (auto [time, cnt]: arr) {
            tot += cnt;
            ans = max(ans, tot);
        }
        return ans;
    }

};