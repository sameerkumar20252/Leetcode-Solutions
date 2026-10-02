class Solution {
public:
    void helper(int open, int close, int n, string& str, vector<string>& ans) {
        if(str.length() == 2*n) {
            ans.push_back(str);
            return;
        }

        if(open < n) {
            str.push_back('(');
            helper(open+1, close, n, str, ans);
            str.pop_back();
        }

        if(close < open) {
            str.push_back(')');
            helper(open, close+1, n, str, ans);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        helper(0, 0, n, str, ans);
        return ans;
    }
};