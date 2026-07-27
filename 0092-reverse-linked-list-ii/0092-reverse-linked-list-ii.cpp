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
    vector<int> stack;
    int i = 0;
    int l = 1, r = 1;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || r > right) {
            return head;
        }
        if(l >= left) {
            stack.push_back(head->val);
        }
        l++, r++;
        reverseBetween(head->next, left, right);

        if(i < stack.size()) {
            head->val = stack[i++];
        }
        
        return head;
    }
};