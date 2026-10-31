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
        auto check = [&](this auto&& check, TreeNode* node, long min_v, long max_v) -> bool {
            if (!node) return true;
            if (node->val >= max_v || node->val <= min_v) {
                return false;
            }
            return check(node->left, min_v, node->val) && check(node->right, node->val, max_v);
        };
        return check(root, LONG_MIN, LONG_MAX);
    }
};