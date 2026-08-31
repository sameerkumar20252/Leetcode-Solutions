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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        ListNode* back = head;
        ListNode* temp = head->next;
        ListNode* front = head->next->next;
        int first = -1;
        int n = 2, last = -1;
        int mx = INT_MIN, mn = INT_MAX;

        while(front != nullptr) {
            if((temp->val < back->val && temp->val < front->val) || 
               (temp->val > back->val && temp->val > front->val)) {
                if(first == -1) {
                    first = n;
                } else {
                    mn = min(mn, n - last);
                    mx = max(mx, n - first);
                    ans[0] = mn;
                    ans[1] = mx;
                }
                last = n;
            }
            n++;
            back = temp;
            temp = front;
            front = front->next;
        }

        return ans;
    }
};