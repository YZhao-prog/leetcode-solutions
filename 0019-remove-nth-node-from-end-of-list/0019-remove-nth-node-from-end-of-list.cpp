/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1, head);
        auto p = dummy, q = dummy;
        int dis = n;
        while (q->next) {
            if (dis) {
                q = q->next;
                --dis;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        p->next = p->next->next;
        return dummy->next;
    }
};