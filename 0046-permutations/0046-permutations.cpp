class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        ranges::sort(nums); 
        do {
            ans.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};