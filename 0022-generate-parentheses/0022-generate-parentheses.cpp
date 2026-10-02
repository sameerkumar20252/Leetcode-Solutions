class Solution {
public:
    void helper(int n, int open, int close, vector<string>& ans, string& str) {
        if(str.length() == 2*n) {
            ans.push_back(str);
            return;
        }

        if(open < n) {
            str.push_back('(');
            helper(n, open + 1, close, ans, str);
            str.pop_back();
        }

        if(close < open) {
            str.push_back(')');
            helper(n, open, close + 1, ans, str);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";

        helper(n, 0, 0, ans, str);

        return ans;
    }
};