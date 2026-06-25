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
    int carry = 0;
    ListNode* helper(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        head->next = helper(head->next);

        int value = head->val;
        value *= 2;
        value += carry; 
        head->val = value % 10;
        carry = value / 10;

        return head;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* ans = helper(head);
        if(carry == 1) {
            return new ListNode(1, ans);
        }

        return ans;
    }
};