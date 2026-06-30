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
    int helper(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int L = helper(root->left);
        if(L == -1) return -1;

        int R = helper(root->right);
        if(R == -1) return -1;

        if(abs(L - R) > 1) return -1;

        return max(L,R)+1;
    }
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};