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
    int rob(TreeNode* root) {
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            auto [l_rob, l_not_rob] = dfs(node->left);
            auto [r_rob, r_not_rob] = dfs(node->right);
            int rob = l_not_rob + r_not_rob + node->val;
            int not_rob = max(l_rob, l_not_rob) + max(r_not_rob, r_rob);
            return {rob, not_rob};
        };
        auto [x, y] = dfs(root);
        return max(x, y);
    }
};