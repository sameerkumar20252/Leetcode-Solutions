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
    TreeNode* buildBST(vector<int>& nums, int st, int end) {
        TreeNode* root = NULL;
        if(st <= end) {
            int mid = st + (end-st)/2;
            root = new TreeNode(nums[mid]);
            root->left = buildBST(nums, st, mid-1);
            root->right = buildBST(nums, mid+1, end);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int st = 0, end = nums.size()-1;

        return  buildBST(nums, st, end);
      
    }
};