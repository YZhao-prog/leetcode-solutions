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
        int x1 = lb(target);
        if (x1 == n || nums[x1] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(x1);
        }
        int x2 = ub(target);

        if (x2 == -1 || nums[x2] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(x2);
        }
        return ans;
    }
};