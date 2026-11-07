class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        while (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            if (--k == 0) {
                return x;
            }
        }
        return -1;
    }
};