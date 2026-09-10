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
    TreeNode* dfs(TreeNode* root, int limit, int sum) {
        if(root == nullptr) return nullptr;
        sum += root->val;
        if(!root->left && !root->right) {
            if(sum < limit) {
                return nullptr;
            } else {
                return root;
            }
        }

        root->left = dfs(root->left, limit, sum);
        root->right = dfs(root->right, limit, sum);

        if(!root->left && !root->right) {
            return nullptr;
        }
        return root;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit, 0);
    }
};