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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> Q;
        vector<int> temp;
        int largest = INT_MIN;
        Q.push(root);
        Q.push(NULL);

        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();

            if(curr == NULL){
                ans.push_back(largest);
                largest = INT_MIN;
                if(!Q.empty()){
                    Q.push(NULL);
                    continue;
                }else{
                    break;
                }
            }
            largest = largest < curr->val ? curr->val : largest;

            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
        }

        return ans;
    }
};