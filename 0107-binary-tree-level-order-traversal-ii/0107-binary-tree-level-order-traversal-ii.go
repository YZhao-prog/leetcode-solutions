

import "slices"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) (ans [][]int) {
    if root == nil {
        return nil
    }
    q := []*TreeNode{root}
    for len(q) != 0 {
        sz := len(q)
        cur := make([]int, sz)
        for i := 0; i < sz; i++ {
            node := q[0]
            q = q[1:]
            cur[i] = node.Val
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        ans = append(ans, cur)
    }
    slices.Reverse(ans)
    return ans
}