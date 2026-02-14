/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lcaDeepestLeaves(root *TreeNode) (ans *TreeNode) {
    maxD := 0
    var dfs func(*TreeNode, int) int
    dfs = func(node *TreeNode, depth int) int {
        if node == nil {
            maxD = max(maxD, depth)
            return depth
        }
        left := dfs(node.Left, depth + 1)
        right := dfs(node.Right, depth + 1)
        if left == right && left == maxD {
            ans = node
        }
        return max(left, right)
    }
    dfs(root, 0)
    return ans
}