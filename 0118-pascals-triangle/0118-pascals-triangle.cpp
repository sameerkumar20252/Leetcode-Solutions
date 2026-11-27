class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1) return {{1}};

        vector<vector<int>> dp(n, vector<int>(2*n-1, 0));
        dp[0][n-1] = 1;
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> row;
        int st = n - 2, end = n;

        for(int i = 1; i < n; i++) {
            for(int j = st; j <= end; j++) {
                if(j == st || j == end) {
                    row.push_back(1);
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                if(dp[i][j]) row.push_back(dp[i][j]);
            }

            ans.push_back(row);
            row.clear();

            st = st - 1, end = end + 1;
        }

        return ans;
    }
};