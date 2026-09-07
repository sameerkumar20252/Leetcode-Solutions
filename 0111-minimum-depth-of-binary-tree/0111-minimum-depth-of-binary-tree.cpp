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
    int dfs(TreeNode* root) {
        if(root == nullptr) return INT_MAX;
        if(!root->left && !root->right) return 1;

        int l = dfs(root->left);
        int r = dfs(root->right);

        return 1 + min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return dfs(root);
    }
};