/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func rangeSumBST(root *TreeNode, low int, high int) (ans int) {
    if root == nil {
        return 0
    }
    x := root.Val
    if x < low {
        return rangeSumBST(root.Right, low, high)
    }
    if x > high {
        return rangeSumBST(root.Left, low, high)
    }
    return x + rangeSumBST(root.Left, low, high) + rangeSumBST(root.Right, low, high)
}