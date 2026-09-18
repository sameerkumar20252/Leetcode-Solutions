class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);

        int i2 = 1, i3 = 1, i5 = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            int i2Ugly = dp[i2] * 2;
            int i3Ugly = dp[i3] * 3;
            int i5Ugly = dp[i5] * 5;

            int mn = min({i2Ugly, i3Ugly, i5Ugly});
            dp[i] = mn;

            if(mn == i2Ugly) {
                i2++;
            }

            
            if(mn == i3Ugly) {
                i3++;
            }

            
            if(mn == i5Ugly) {
                i5++;
            }
        }

        return dp[n];
    }
};