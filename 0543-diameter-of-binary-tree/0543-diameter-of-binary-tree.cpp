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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto get_height = [&](this auto&& get_height, TreeNode* node) {
            if (!node) return 0;
            int lh = get_height(node->left);
            int rh = get_height(node->right);
            int len = 0;
            if (node->left) len += 1 + lh - 1;
            if (node->right) len += 1 + rh - 1;
            ans = max(ans, len);
            return max(lh, rh) + 1;
        };
        get_height(root);
        return ans;
    }
};