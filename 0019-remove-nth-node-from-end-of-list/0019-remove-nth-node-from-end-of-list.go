/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    dummy := &ListNode{Next: head}
    p, q := dummy, dummy
    for i := 0; i < n; i++ {
        q = q.Next
    }
    for q.Next != nil {
        p = p.Next
        q = q.Next
    }
    p.Next = p.Next.Next
    return dummy.Next
}