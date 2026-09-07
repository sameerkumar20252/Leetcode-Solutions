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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push({root, 1});
        int ans = INT_MAX;

        while(Q.size() > 0) {
            auto[curr, d] = Q.front();
            Q.pop();

            if(!curr->left && !curr->right) {
                ans = min(ans, d);
            }

            if(curr->left) {
                Q.push({curr->left, d + 1});
            }
            if(curr->right) {
                Q.push({curr->right, d + 1});
            }
        }

        return ans;
    }
};