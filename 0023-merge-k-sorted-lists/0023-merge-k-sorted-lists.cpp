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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                dummy->next = l1;
                l1 = l1->next;;
            }
            else {
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }

        if(l1) {
            dummy->next = l1;
        }

        if(l2) {
            dummy->next = l2;
        }

        return head->next;
    }

    ListNode* divide(vector<ListNode*>& lists, int st, int end) {
        if(st == end) return lists[st];

        int mid = st + (end - st)/2;

        ListNode* L1 = divide(lists, st, mid);
        ListNode* L2 = divide(lists, mid+1, end);

        return merge(L1, L2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }
};