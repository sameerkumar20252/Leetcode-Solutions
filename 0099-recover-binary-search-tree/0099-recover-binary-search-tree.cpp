/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* prev = nullptr;

        TreeNode* curr = root;
        while(curr) {
            if(curr->left == nullptr) {
                if(prev && curr->val < prev->val) {
                    if(!first) {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                TreeNode* IS = curr->left;
                while(IS->right != nullptr && IS->right != curr) {
                    IS = IS->right;
                }
                if(IS->right == nullptr) {
                    IS->right = curr;
                    curr = curr->left;
                } else {
                    IS->right = nullptr;
                    if(prev && curr->val < prev->val) {
                        if(!first) {
                            first = prev;
                        }
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        swap(first->val, second->val); 
    }
};