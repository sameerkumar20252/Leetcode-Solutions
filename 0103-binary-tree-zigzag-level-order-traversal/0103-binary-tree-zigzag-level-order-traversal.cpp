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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> Q;
        vector<int> temp;
        int level = 1;
        Q.push(root);
        Q.push(NULL);
        bool flag = false;

        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            if(curr == NULL){
                if(level%2 != 0){
                    ans.push_back(temp);
                } 
                else {
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                level++;
                temp.clear();
                if(!Q.empty()){
                    Q.push(NULL);
                    continue;
                }else{
                    break;
                }
            }
            temp.push_back(curr->val);

            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }

        return ans;
    }
};