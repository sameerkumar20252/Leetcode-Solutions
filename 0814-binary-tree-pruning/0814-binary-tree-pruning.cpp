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
    bool pruning(TreeNode* root){
        if(root == nullptr){
            return false;
        }
        bool left = pruning(root->left);
        if(!left) root->left = nullptr;

        bool right = pruning(root->right);
        if(!right) root->right = nullptr;

        return (!left && !right && root->val==0) ? 
               false : true;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return !pruning(root) ? NULL : root;
    }
};