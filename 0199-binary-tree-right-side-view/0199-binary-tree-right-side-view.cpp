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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        auto get_right = [&](this auto&& get_right, TreeNode* node, int depth) -> void {
            if (!node) return;
            if (depth == ans.size()) ans.push_back(node->val);
            get_right(node->right, depth + 1);
            get_right(node->left, depth + 1);
        };
        get_right(root, 0);
        return ans;
    }
};