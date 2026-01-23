/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    p, q := head, head
    for q != nil && q.Next != nil {
        p = p.Next
        q = q.Next.Next
        if p == q {
            return true
        }
    }
    return false
}