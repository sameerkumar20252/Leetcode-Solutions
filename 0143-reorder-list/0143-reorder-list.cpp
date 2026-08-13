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
    void reorderList(ListNode* head) {
        if(head->next == nullptr) return;

        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* last = nullptr;

        while(fast != nullptr && fast->next != nullptr) {
            last = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;
        if(fast == nullptr) {
            curr = slow;
            forward = curr->next;
        } else {
            curr = slow->next;
            last = slow;
            forward = curr->next;
        }

        //reverse second half
        while(1) {
            curr->next = prev;
            prev = curr;
            curr = forward;
            if(curr == nullptr) break;
            forward = forward->next;
        }

        last->next = prev;

        ListNode* temp1 = head;
        ListNode* temp2 = last->next;

        //reorder
        while(1) {
            ListNode* t1 = temp1->next;
            ListNode* t2 = temp2->next;

            temp1->next = temp2;
            if(t1 == prev) break;
            temp2->next = t1;
            temp1 = t1;
            temp2 = t2;
            if(temp2 == nullptr){
                temp1->next = nullptr;
                break;
            }
        }
    }
};