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
    ListNode* middleNode(ListNode* head) {
        auto p = head, q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }

    ListNode* reverseNode(ListNode* head) {
        auto cur = head;
        ListNode* prev = nullptr;
        while (cur) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        auto mid = middleNode(head);
        auto head2 = reverseNode(mid);
        while (head2->next) {
            auto nxt1 = head->next;
            auto nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt1;
            head = nxt1;
            head2 = nxt2;
        }
    }
};