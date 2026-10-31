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
    bool isValidBST(TreeNode* root) {
        auto check = [&](this auto&& check, TreeNode* node, long& pre) -> bool {
            if (!node) return true;
            if (!check(node->left, pre)) return false;
            if (node->val <= pre) return false;
            pre = node->val;
            return check(node->right, pre);
        };
        long pre = LONG_MIN;
        return check(root, pre);
    }
};