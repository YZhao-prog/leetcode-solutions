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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool even = false;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> cur;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                cur.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (even) reverse(cur.begin(), cur.end());
            ans.push_back(cur);
            even = !even;
        }
        return ans;
    }
};