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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> vec;
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;

        while(Q.size() > 0) {
            int size = Q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();
                if(level % 2 != 0) {
                    vec.push_back(curr);
                }
                if(curr->left) {
                    Q.push(curr->left);
                }
                if(curr->right) {
                    Q.push(curr->right);
                }
            }
            if(level % 2 != 0) {
                int i = 0, j = vec.size() - 1;
                while(i < j) {
                    swap(vec[i]->val, vec[j]->val);
                    i++; j--;
                }
                vec.clear();
            }
            level++;
        }

        return root;
    }
};