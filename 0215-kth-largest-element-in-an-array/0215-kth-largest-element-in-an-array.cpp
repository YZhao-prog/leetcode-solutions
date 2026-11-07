class Solution {
public:
    int quickSelect(vector<int>& nums, int k, int l, int r) {
        if (l > r) {
            return -1;
        }
        swap(nums[l], nums[l + rand() % (r - l + 1)]);
        int x = nums[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] > x) {
                --j;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] < x) {
                ++i;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        if (nums.size() - i > k) {
            return quickSelect(nums, k, i + 1, r);
        } else if (nums.size() - i < k) {
            return quickSelect(nums, k, l, i - 1);
        } else {
            return x;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = quickSelect(nums, k, 0, n - 1);
        return ans;
    }
};