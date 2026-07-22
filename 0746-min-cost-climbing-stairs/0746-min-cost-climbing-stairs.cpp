class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0];
        int b = cost[1];

        for(int i = 2; i < cost.size(); i++) {
            int result = min(a + cost[i], b + cost[i]);
            a = b;
            b = result;
        }

        return min(a, b);
    }
};