/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "math"
func getMinimumDifference(root *TreeNode) int {
    prev, ans := -1, math.MaxInt
    var inorder func(*TreeNode)
    inorder = func(node *TreeNode) {
        if node == nil {
            return
        }
        inorder(node.Left)
        if prev != -1 {
            ans = min(ans, node.Val - prev)
        }
        prev = node.Val
        inorder(node.Right) 
    }
    inorder(root)
    return ans
}