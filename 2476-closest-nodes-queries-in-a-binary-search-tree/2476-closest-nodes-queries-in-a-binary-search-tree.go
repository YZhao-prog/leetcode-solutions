/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func closestNodes(root *TreeNode, queries []int) (ans [][]int) {
    var inorder func(*TreeNode)
    var list []int
    inorder = func(node *TreeNode) {
        if node == nil {
            return
        }
        inorder(node.Left)
        list = append(list, node.Val)
        inorder(node.Right)
    }
    inorder(root) // O(n)
    for _, t := range queries {
        x, y := 0, 0
        l, r := -1, len(list)
        for l + 1 < r {
            m := l + (r - l) / 2
            if list[m] <= t {
                l = m
            } else {
                r = m
            }
        }
        if l == -1 {
            x = -1
        } else {
            x = list[l]
        }
        l, r = -1, len(list)
        for l + 1 < r {
            m := l + (r - l) / 2
            if list[m] < t {
                l = m
            } else {
                r = m
            }
        }
        if r == len(list) {
            y = -1
        } else {
            y = list[r]
        }
        ans = append(ans, []int{x, y})
    }
    return ans
}