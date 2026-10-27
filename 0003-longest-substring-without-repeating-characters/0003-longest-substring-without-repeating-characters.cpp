class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> map;
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            map[s[r]]++;
            while (map[s[r]] > 1) {
                map[s[l]]--;
                ++l;
            }
            ans = max(ans, r -l + 1);
        }
        return ans;
    }
};