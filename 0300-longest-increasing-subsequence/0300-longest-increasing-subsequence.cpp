class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> g{nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] > g.back()) {
                g.push_back(nums[i]);
            } else {
                auto j = lower_bound(g.begin(), g.end(), nums[i]);
                *j = nums[i];
            }
        }
        return g.size();
    }
};