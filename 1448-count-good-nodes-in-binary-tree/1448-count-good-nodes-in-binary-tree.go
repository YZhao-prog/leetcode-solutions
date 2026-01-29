import "math"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func dfs(x *TreeNode, mx int) int {
    if x == nil {
        return 0
    }
    left := dfs(x.Left, max(mx, x.Val))
    right := dfs(x.Right, max(mx, x.Val))
    if mx <= x.Val {
        return left + right + 1
    }
    return left + right
}
func goodNodes(root *TreeNode) int {
    return dfs(root, math.MinInt)
}