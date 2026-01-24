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

func reorderList(head *ListNode)  {
    // 1 2 3
    // 5 4 3

    // 1 2 3
    // 4 3
    m := middileNode(head)
    head2 := reverseList(m)
    p, q := head, head2
    for q.Next != nil {
        nxtp := p.Next
        nxtq := q.Next
        p.Next = q
        q.Next = nxtp
        p = nxtp
        q = nxtq
    }
}