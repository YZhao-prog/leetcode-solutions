/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) (ans [][]int) {
    if root == nil {
        return nil
    }
    q := []*TreeNode{root}
    for len(q) != 0 {
        sz := len(q)
        level := make([]int, sz)
        for i := 0; i < sz; i++ {
            node := q[0]
            q = q[1:]
            if len(ans) % 2 == 1 {
                level[sz - 1 - i] = node.Val
            } else {
                level[i] = node.Val
            }
            if node.Left != nil {
                q = append(q, node.Left)
            }
            if node.Right != nil {
                q = append(q, node.Right)
            }
        }
        ans = append(ans, level)
    }
    return ans
}