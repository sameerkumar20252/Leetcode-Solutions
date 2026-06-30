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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> Q;
        int data = 0;

        Q.push(root);
        Q.push(NULL);

        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();

            if(curr == NULL){
                ans.push_back(data);
                if(!Q.empty()){
                    Q.push(NULL);
                    continue;
                }else{
                    break;
                }
            }

            data = curr->val;

            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }

        return ans;
    }
};