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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long sum = 0;
        vector<long long> vec;
        int level = 0, idx = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            
            if(curr == NULL){
                vec.push_back(sum);
                sum = 0;
                if(!Q.empty()){
                    Q.push(NULL);
                    continue;
                }else{
                    break;
                }
            }
            sum += curr->val;
            if(curr->left != nullptr){
                Q.push(curr->left);
            }
            if(curr->right != nullptr){
                Q.push(curr->right);
            }
        }
        sort(vec.begin(),vec.end());
        if(k > vec.size()) return -1;
        return vec[vec.size()-k];
    }
};