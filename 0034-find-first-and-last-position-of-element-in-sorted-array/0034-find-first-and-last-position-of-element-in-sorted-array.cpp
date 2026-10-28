class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        auto lb = [&](int target) -> int {
            int l = -1, r = n;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (nums[m] < target) {
                    l = m;
                } else {
                    r = m;
                }
            }
            return r;
        };

        auto ub = [&](int target) -> int {
            int l = -1, r = n;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (nums[m] <= target) {
                    l = m;
                } else {
                    r = m;
                }
            }
            return l;
        };
        vector<int> ans;
        int start = lb(target);
        int end = ub(target);
        if (start == n || nums[start] != target) {
            return {-1, -1};
        } 
        return {start, end};
    }
};