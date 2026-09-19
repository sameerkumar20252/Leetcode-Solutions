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
    int helper(TreeNode* root, bool isValid) {
        if(root == nullptr) return 0;
        if(!root->left && !root->right && isValid) return root->val;

        int l = helper(root->left, true);
        int r = helper(root->right, false);

        return l + r;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};