/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    dummy := &ListNode{Next: head}
    p := dummy
    for p.Next != nil && p.Next.Next != nil {
        if p.Next.Val == p.Next.Next.Val {
            delete_val := p.Next.Val
            for p.Next != nil && p.Next.Val == delete_val {
                p.Next = p.Next.Next
            }
        } else {
            p = p.Next
        }
    }
    return dummy.Next
}