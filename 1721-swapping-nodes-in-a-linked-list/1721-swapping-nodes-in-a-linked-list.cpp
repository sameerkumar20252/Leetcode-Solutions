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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }

        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        temp = head;
        int a = 1;

        while(temp != nullptr) {
            if(a == k) {
                temp1 = temp;
            }
            if(a == (n - k + 1)) {
                temp2 = temp;
                if(temp1 != nullptr) {
                    break;
                }
            }
            a++;
            temp = temp->next;
        }

        swap(temp2->val, temp1->val);

        return head;
    }
};