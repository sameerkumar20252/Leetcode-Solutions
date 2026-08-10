class Solution {
public:
    int helper(vector<string>& strs, int idx, int m, int n, vector<vector<vector<int>>>& dp) {
        if(idx < 0) {
            return 0;
        }

        if(dp[idx+1][m][n]  != -1) {
            return dp[idx+1][m][n];
        }

        int x = 0,//no. of 0
            y = 0;//no. of 1
        for(char ch : strs[idx]) {
            if(ch == '0') x++;
            else y++;
        }

        if(m >= x && n >= y) {
            int include = helper(strs, idx - 1, m - x, n - y, dp) + 1;
            int exclude = helper(strs, idx - 1, m, n, dp);
            return dp[idx+1][m][n] = max(include, exclude);
        }
        else {
            return dp[idx+1][m][n] = helper(strs, idx - 1, m, n, dp);
        }
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, strs.size() - 1, m, n, dp);
    }
};