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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        queue<TreeNode*> Q;
        Q.push(root);

        while(Q.size() > 0) {
            int size = Q.size();
            double sum = 0.0;

            for(int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                sum += curr->val * 1.0;
                if(curr->left) {
                    Q.push(curr->left);
                }
                if(curr->right) {
                    Q.push(curr->right);
                }
            }

            ans.push_back(sum / size);
        }

        return ans;
    }
};