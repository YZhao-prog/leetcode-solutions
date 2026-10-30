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
    bool isSymmetric(TreeNode* root) {
        auto check = [&](this auto&& check, TreeNode* p, TreeNode* q) {
            if (!p || !q) return p == q;
            return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
        };
        return check(root->left, root->right);
    }
};