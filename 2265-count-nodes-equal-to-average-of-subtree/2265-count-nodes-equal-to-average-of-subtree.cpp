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
    using T = pair<int,int>;
    T helper(TreeNode* root, int& ans) {
        if(root == nullptr) {
            return {0, 0};
        }

        T left = helper(root->left, ans);
        T right = helper(root->right, ans);

        int sum = left.first + right.first + root->val;
        int n = left.second + right.second + 1;

        if(sum/n == root->val) {
            ans++;
        }

        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        helper(root, ans);

        return ans;
    }
};