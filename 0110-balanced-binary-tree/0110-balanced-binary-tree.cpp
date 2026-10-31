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
    bool isBalanced(TreeNode* root) {
        auto get_height = [&](this auto&& get_height, TreeNode* node) -> int {
            if (!node) return 0;
            int lh = get_height(node->left), rh = get_height(node->right);
            if (abs(lh - rh) > 1 || lh == -1 || rh == -1) return -1;
            return max(lh, rh) + 1;
        };
        return get_height(root) != -1;
    }
};
