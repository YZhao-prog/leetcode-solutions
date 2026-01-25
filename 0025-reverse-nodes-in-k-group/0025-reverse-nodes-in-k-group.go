/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
import "fmt"
func reverseKGroup(head *ListNode, k int) *ListNode {
    n := 0
    dummy := &ListNode{Next: head}
    p := dummy.Next
    for p != nil {
        p = p.Next
        n++
    }
    p = dummy
    cur := head
    for n >= k {
        n -= k
        var prev *ListNode = nil
        for i := 0; i < k; i++ {
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