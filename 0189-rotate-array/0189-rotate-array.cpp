class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 4 3 2 1 7 6 5
        auto reverse = [&](int l, int r) {
            while (l < r) {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
        };
        int n = nums.size();
        k = k % n;
        reverse(0, n - k - 1);
        reverse(n - k, n - 1);
        reverse(0, n - 1);
    }
};