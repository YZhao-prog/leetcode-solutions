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
        p = p.Next
        q = q.Next.Next
    }
    return p
}

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

func isPalindrome(head *ListNode) bool {
    mid := middleNode(head)
    head2 := reverseList(mid)
    p, q := head, head2
    for p != nil && q != nil {
        if p.Val != q.Val {
            return false
        }
        p = p.Next
        q = q.Next
    }
    return true
}