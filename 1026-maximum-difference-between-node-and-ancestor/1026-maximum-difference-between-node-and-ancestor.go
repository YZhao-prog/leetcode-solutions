/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxAncestorDiff(root *TreeNode) (ans int) {
    var dfs func(*TreeNode, int, int)
    dfs = func(node *TreeNode, mx int, mn int) {
        if node == nil {
            return
        }
        val := node.Val
        ans = max(ans, mx - val, val - mn)
        mx = max(mx, val)
        mn = min(mn, val)
        dfs(node.Left, mx, mn)
        dfs(node.Right, mx, mn)
    }
    dfs(root, root.Val, root.Val)
    return ans
}