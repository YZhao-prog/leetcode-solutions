/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
    p, q := root.Left, root.Right
    var check func(*TreeNode, *TreeNode) bool
    check = func(p, q *TreeNode) bool {
        if p == nil || q == nil {
            return p == q
        }
        return p.Val == q.Val && check(p.Left, q.Right) && check(p.Right, q.Left)
    }
    return check(p, q)
}