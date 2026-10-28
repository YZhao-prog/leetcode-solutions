class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int end = nums[n - 1];
        auto is_left = [&](int x) -> bool {
            if (nums[x] > end) {
                return target > end && nums[x] >= target;
            } else {
                return target > end || nums[x] >= target;
            }
        };
        int l = -1, r = n - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (is_left(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        return nums[r] == target ? r : -1;
    }
};