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

func doubleIt(head *ListNode) *ListNode {
    p, dummy := reverseList(head), &ListNode{Val: 0}
    r := dummy
    carry := 0
    for p != nil || carry != 0 {
        if (p != nil) {
            carry += p.Val * 2
            p = p.Next
        }
        r.Next = &ListNode{Val: carry % 10}
        r = r.Next
        carry /= 10
    }
    return reverseList(dummy.Next)
}