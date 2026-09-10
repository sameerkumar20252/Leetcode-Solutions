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
    TreeNode* dummy = new TreeNode(-1);
    TreeNode* curr = dummy;
    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        inorder(root->left);
        dummy->right = new TreeNode(root->val);
        dummy = dummy->right;
        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);

        return curr->right;
    }
};