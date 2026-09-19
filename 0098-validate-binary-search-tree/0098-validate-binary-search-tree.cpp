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
    bool isValid(TreeNode* root, TreeNode* l, TreeNode* r) {
        if(root == nullptr) {
            return true;
        }

        if(l) {
            if(root->val <= l->val) return false;
        }
        if(r) {
            if(root->val >= r->val) return false;
        }

        bool x = isValid(root->left, l, root);
        if(!x) return false;

        bool y = isValid(root->right, root, r);
        if(!y) return false;

        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }
};