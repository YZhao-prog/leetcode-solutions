/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var prev *ListNode = nil
    cur := head
    for cur != nil {
        nxt := cur.Next
        cur.Next = prev
        prev = cur
        cur = nxt
    }
    return prev
}
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    p, q, dummy := reverseList(l1), reverseList(l2), &ListNode{Val: 0}
    r := dummy
    carry := 0
    for p != nil || q != nil || carry != 0 {
        if (p != nil) {
            carry += p.Val
            p = p.Next
        }
        if (q != nil) {
            carry += q.Val
            q = q.Next
        }
        r.Next = &ListNode{Val: carry % 10}
        r = r.Next
        carry /= 10
    }
    return reverseList(dummy.Next)
}