class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int s = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            s += nums[r];
            while (s - nums[l] >= target) {
                s -= nums[l++];
            }
            if (s >= target) {
                ans = min(ans, r - l + 1);
            }
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};