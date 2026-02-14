/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
    hp, hq := -1, -1
    fa := make(map[*TreeNode]*TreeNode)
    var dfs func(*TreeNode, *TreeNode, int)
    dfs = func(node *TreeNode, prev *TreeNode, h int) {
        if node == nil {
            return
        }
        fa[node] = prev
        if node == p {
            hp = h
        }
        if node == q {
            hq = h
        }
        dfs(node.Left, node, h + 1)
        dfs(node.Right, node, h + 1)
    }
    dfs(root, nil, 0)
    if hp < hq {
        temp := q
        q = p
        p = temp
    }
    gap := max(hp - hq, hq - hp)
    for gap > 0 {
        p = fa[p]
        gap--
    }
    for p != q {
        p = fa[p]
        q = fa[q]
    }
    return p
}