/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto p = head, q = head;
        while (q && q->next) {
            q = q->next->next;
            p = p->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};