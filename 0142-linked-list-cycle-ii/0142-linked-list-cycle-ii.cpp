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
    ListNode *detectCycle(ListNode *head) {
        // ----------
        //      |____|
        //    a    b     tot = a + b
        // p: x  q: 2x
        // 2x - x = nb
        // x - a + a = x = nb
        auto p = head, q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                auto r = head;
                while (p != r) {
                    p = p->next;
                    r = r->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};