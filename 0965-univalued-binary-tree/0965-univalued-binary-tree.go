/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
    var dfs func(*TreeNode, int) bool
    dfs = func(node *TreeNode, value int) bool {
        if node == nil {
            return true
        }
        if value != node.Val {
            return false
        }
        return dfs(node.Left, node.Val) && dfs(node.Right, node.Val)
    }
    return dfs(root, root.Val)
}