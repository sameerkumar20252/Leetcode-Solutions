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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;

        while(Q.size() > 0) {
            int size = Q.size();

            int sum = 0;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                sum += curr->val;
                if(curr->left) {
                    Q.push(curr->left);
                }
                if(curr->right) {
                    Q.push(curr->right);
                }
            }
            if(Q.size() == 0) {
                ans = sum;
            }
        }

        return ans;
    }
};