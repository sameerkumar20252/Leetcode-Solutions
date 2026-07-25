class Solution {
public:
    int minCost(vector<int>& cost, int n, vector<int>& dp) {
        if(n <= 1) {
            return dp[n] = 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int prev1 = minCost(cost, n - 2, dp) + cost[n - 2];
        int prev2 = minCost(cost, n - 1, dp) + cost[n - 1];

        return dp[n] = min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        return minCost(cost, n, dp);

        // return result;
    }
};