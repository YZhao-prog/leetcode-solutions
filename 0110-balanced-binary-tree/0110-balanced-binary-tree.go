/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func abs(x int) int { if x < 0 { return -x }; return x }
func isBalanced(root *TreeNode) bool {
    var get_height func(*TreeNode) int
    get_height = func(node *TreeNode) int {
        if node == nil {
            return 0
        }
        left := get_height(node.Left)
        right := get_height(node.Right)
        if right == -1 || left == -1 || abs(left - right) > 1 {
            return -1
        }
        return max(left, right) + 1
    }
    return get_height(root) != -1
}