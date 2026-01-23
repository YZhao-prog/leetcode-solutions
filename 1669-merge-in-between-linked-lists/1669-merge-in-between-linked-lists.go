/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    t := list2
    for t.Next != nil {
        t = t.Next
    }
    cur := list1
    for i := 0; i < a - 1; i++ {
        cur = cur.Next
    }
    q := cur.Next
    cur.Next = list2
    for i := 0; i < b - a + 1; i++ {
        q = q.Next
    }
    t.Next = q
    return list1
}