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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        if(head->next == nullptr) {
            return head;
        }
        ListNode* dummy = nullptr;
        ListNode* c1 = head;
        ListNode* c2 = head->next;
        ListNode* ans = head->next;;

        while(c2 != nullptr) {
            if(dummy != nullptr) {
                dummy->next = c2;
            }
            c1->next = c2->next;
            c2->next = c1;
            dummy = c1;
            c1 = c1->next;
            if(c1 == nullptr) {
                break;
            }
            c2 = c1->next;
        }

        return ans;
    }
};