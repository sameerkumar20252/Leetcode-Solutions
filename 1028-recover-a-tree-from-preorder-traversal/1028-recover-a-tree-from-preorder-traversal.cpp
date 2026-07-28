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
    TreeNode* helper(string& traversal, int& level, int& idx) {
        if(idx >= traversal.size()) {
            return nullptr;
        }
        string s = "";
        while(idx < traversal.length() && traversal[idx] != '-') {
            s += traversal[idx];
            idx++;
        }
        idx--;

        TreeNode* node = new TreeNode(stoi(s));
        if(idx == traversal.size() - 1) {
            idx++;
            return node;
        }
        idx++;
        int l = level;
        level = 0;
        while(traversal[idx] == '-') {
            level++;
            idx++;
        }
        if(level == l + 1) {
            node->left = helper(traversal, level, idx);
        }
        // else {
        //     return node;
        // }

        if(level == l + 1) {
            node->right = helper(traversal, level, idx);
        }

        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        int level = 0;
        return helper(traversal, level, idx);
    }
};