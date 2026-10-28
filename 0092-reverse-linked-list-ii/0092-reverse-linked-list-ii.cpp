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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1, head);
        auto before = dummy;
        for (int i = 0; i < left - 1; i++) {
            before = before->next;
        }
        auto cur = before->next;
        int cnt = right - left + 1;
        ListNode* prev = nullptr;
        while (cnt) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            --cnt;
        }
        before->next->next = cur;
        before->next = prev;
        return dummy->next;
    }
};