class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int x = nums[i];
            if (i != 0 && x == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            // if (x + nums[j] + nums[j + 1] > 0) {
            //     break;
            // }
            // if (x + nums[k - 1] + nums[k] < 0) {
            //     break;
            // }
            while (j < k) {
                int sum = x + nums[j] + nums[k];
                if (sum < 0) {
                    ++j;
                } else if (sum > 0) {
                    --k;
                } else {
                    ans.push_back({x, nums[j], nums[k]});
                    ++j;
                    while (j < k && nums[j] == nums[j - 1]) ++j;
                    --k;
                    while (j < k && nums[k] == nums[k + 1]) --k;
                }
            }
        }
        return ans;
    }
};