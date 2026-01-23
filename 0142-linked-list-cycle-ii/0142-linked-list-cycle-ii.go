/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func detectCycle(head *ListNode) *ListNode {
    p, q := head, head
    for q != nil && q.Next != nil {
        p = p.Next
        q = q.Next.Next
        if (p == q) {
            r := head
            for p != r {
                p = p.Next
                r = r.Next
            }
            return p
        }
    }
    return nil
}