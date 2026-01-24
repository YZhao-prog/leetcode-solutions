/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    dummy := &ListNode{Next: head}
    before := dummy
    for i := 0; i < left - 1; i++ {
        before = before.Next
    }

    cur := before.Next
    var prev *ListNode = nil
    for i := 0; i < right - left + 1; i++ {
        nxt := cur.Next
        cur.Next = prev
        prev = cur
        cur = nxt
    }
    before.Next.Next = cur
    before.Next = prev
    return dummy.Next
}