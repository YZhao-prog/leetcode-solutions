/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> fa;
        TreeNode* targetNode;
        auto dfs = [&](this auto&& dfs, TreeNode* node, TreeNode* pre) {
            if (!node) return;
            if (node == target) {
                targetNode = node;
            }
            if (pre) fa[node] = pre;
            dfs(node->left, node);
            dfs(node->right, node);
        };
        dfs(root, nullptr);
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        unordered_set<TreeNode*> vis;
        q.push({targetNode, 0});
        while (!q.empty()) {
            auto [node, dis] = q.front();
            vis.insert(node);
            q.pop();
            if (dis == k) {
                ans.push_back(node->val);
                continue;
            }
            if (node->left && !vis.count(node->left)) {
                q.push({node->left, dis + 1});
            }
            if (node->right && !vis.count(node->right)) {
                q.push({node->right, dis + 1});
            }
            if (fa.count(node) && !vis.count(fa[node])) {
                q.push({fa[node], dis + 1});
            }
        }
        return ans;
    }
};