/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    p, q := head, head
    for q != nil && q.Next != nil {
        q = q.Next.Next
        p = p.Next
    }
    return p
}