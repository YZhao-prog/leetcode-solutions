class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        auto bs = [&]() -> int {
            int l = -1, r = n - 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (nums[m] < nums[n - 1]) {
                    r = m;
                } else {
                    l = m;
                }
            }
            return r;
        };
        return nums[bs()];
    }
};