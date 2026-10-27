class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int preMax = 0, sufMax = 0;
        int ans = 0;
        while (l < r) {
            preMax = max(preMax, height[l]);
            sufMax = max(sufMax, height[r]);
            if (preMax <= sufMax) {
                ans += preMax - height[l];
                ++l;
            } else {
                ans += sufMax - height[r];
                --r;
            }
        }
        return ans;
    }
};