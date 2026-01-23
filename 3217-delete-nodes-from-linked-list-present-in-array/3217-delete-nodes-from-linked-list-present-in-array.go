/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func modifiedList(nums []int, head *ListNode) *ListNode {
    has := make(map[int]bool, len(nums))
    for _, val := range nums {
        has[val] = true
    }
    dummy := &ListNode{Next: head}
    cur := dummy
    for cur.Next != nil {
        val := cur.Next.Val
        if has[val] {
            cur.Next = cur.Next.Next
        } else {
            cur = cur.Next
        }
    }
    return dummy.Next
}