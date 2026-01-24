/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middileNode(head *ListNode) *ListNode {
    p, q := head, head
    for q!= nil && q.Next != nil {
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

func pairSum(head *ListNode) (ans int) {
    mid := middileNode(head)
    head2 := reverseList(mid)
    p, q := head, head2
    for p != nil && q != nil {
        ans = max(ans, p.Val + q.Val)
        p = p.Next
        q = q.Next
    }
    return ans
}