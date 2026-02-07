/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
    limit -= root.Val
    if root.Left == nil && root.Right == nil {
        if limit <= 0 {
            return root
        } else {
            return nil
        }
    }
    if root.Left != nil {
        root.Left = sufficientSubset(root.Left, limit)
    }
    if root.Right != nil {
        root.Right = sufficientSubset(root.Right, limit)
    }
    if root.Left != nil || root.Right != nil {
        return root
    } else {
        return nil
    }
}