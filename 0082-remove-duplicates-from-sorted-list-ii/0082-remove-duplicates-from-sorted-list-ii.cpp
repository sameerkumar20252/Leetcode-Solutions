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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* x = nullptr;
        ListNode* newhead = nullptr;
        bool flag = true;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val == temp->next->val){
                int a = temp->val;
                while(temp!=NULL && temp->val==a){
                    x = temp;
                    temp = temp->next;
                    x->next = NULL;
                }
                if(prev!=NULL){
                    prev->next = temp;
                }
            }else{
                if(flag){
                    newhead = temp;
                    flag = false;
                }
                prev = temp;
                temp = temp->next;
            }
        }
        if(newhead==NULL){
            return temp;
        }
        return newhead;
    }
};