/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            int l = dfs(node->left);
            int r = dfs(node->right);
            ans = max(ans, l + r + node->val);
            return max(l, r) + node->val > 0 ? max(l, r) + node->val : 0;
        };
        dfs(root);
        return ans;
    }
};