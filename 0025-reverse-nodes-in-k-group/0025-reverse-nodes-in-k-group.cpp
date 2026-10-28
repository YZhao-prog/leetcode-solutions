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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cur = head;
        int n = 0;
        while (cur) {
            cur = cur->next;
            ++n;
        }
        ListNode* dummy = new ListNode(-1, head);
        auto before = dummy;
        cur = before->next;;
        while (n >= k) {
            n -= k;
            int cnt = k;
            ListNode* prev = nullptr;
            while (cnt) {
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
                --cnt;
            }
            auto new_before = before->next;
            before->next->next = cur;
            before->next = prev;
            before = new_before;
        }
        return dummy->next;
    }
};