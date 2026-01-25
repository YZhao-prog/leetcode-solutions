/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    dummy := &ListNode{Next: head}
    p := dummy
    cur := p.Next
    for cur != nil && cur.Next != nil {
        var prev *ListNode = nil
        for i := 0; i < 2; i++ {
            nxt := cur.Next
            cur.Next = prev
            prev = cur
            cur = nxt
        }
        pnxt := p.Next
        p.Next.Next = cur
        p.Next = prev
        p = pnxt
    }
    return dummy.Next
}