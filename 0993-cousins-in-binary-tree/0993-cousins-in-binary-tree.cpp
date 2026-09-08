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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,int>> Q;
        Q.push({root, -1});
        int par1 = -1, par2 = -1;

        while(Q.size() > 0) {
            int size = Q.size();
            if(par1 != -1 || par2 != -1) {
                break;
            }

            for(int i = 0; i < size; i++) {
                auto[curr, par] = Q.front();
                Q.pop();
                if(curr->val == x) {
                    par1 = par;
                }
                if(curr->val == y) {
                    par2 = par;
                }

                if(curr->left) {
                    Q.push({curr->left, curr->val});
                }
                if(curr->right) {
                    Q.push({curr->right, curr->val});
                }
            }
        }

        if(par1 == -1 || par2 == -1)  return false;
        return par1 != par2;
    }
};