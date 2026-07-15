class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        //n = 1
        int a = costs[0] + 1;
        if(n == 1) return a;
        //n = 2
        int b = min(costs[1] + 4, a + costs[1] + 1);
        if(n == 2) return b;
        //n = 3
        int c = min(costs[2] + 9, a + costs[2] + 4);
        c = min(c, b + costs[2] + 1);
        if(n == 3) return c;

        // vector<int> dp(n+1);
        // dp[0] = 0;
        // dp[1] = a;
        // dp[2] = b;
        // dp[3] = c;
        int result = 0;

        for(int i = 4; i <= n; i++) {
            int x = a + (costs[i-1] + 9);
            int y = b + (costs[i-1] + 4);
            int z = c + (costs[i-1] + 1);

            result = min({x, y, z}); 
            a = b;
            b = c;
            c = result;
        }

        return result;
    }
};