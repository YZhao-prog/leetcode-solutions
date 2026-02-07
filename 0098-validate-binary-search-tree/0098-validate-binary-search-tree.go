

import "math"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
    var dfs func(int, int, *TreeNode) bool
    dfs = func(l int, r int, node *TreeNode) bool {
        if node == nil {
            return true
        }
        if node.Val < r && node.Val > l {
            return dfs(l, node.Val, node.Left) && dfs(node.Val, r, node.Right)
        }
        return false
    }
    return dfs(math.MinInt, math.MaxInt, root)
}