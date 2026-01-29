/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(x *TreeNode, sum int) int {
    if x == nil {
        return 0
    }
    sum = sum * 10 + x.Val
    if x.Left == nil && x.Right == nil {
        return sum
    }
    return dfs(x.Left, sum) + dfs(x.Right, sum);
}

func sumNumbers(root *TreeNode) int {
    return dfs(root, 0)
}