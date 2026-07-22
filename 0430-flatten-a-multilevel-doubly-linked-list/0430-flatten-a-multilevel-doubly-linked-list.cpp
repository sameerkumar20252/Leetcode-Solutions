/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* last = nullptr;
    void dfs(Node* head) {
        Node* prev = nullptr;
        while(head != nullptr) {
            prev = head;
            head = head->next;
            last = prev;
            if(prev->child) {
                prev->next = prev->child;
                prev->next->prev = prev;
                Node* temp = prev->child;
                prev->child = nullptr;
                dfs(temp);
                last->next = head;
                if(head) {
                    head->prev = last;
                }
            }
        }
    }

    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};