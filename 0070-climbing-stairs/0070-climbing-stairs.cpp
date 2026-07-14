class Solution {
public:
    int climbStairs(int n) {
        //Tabulation(Memory Optimized)
        if(n == 1 || n == 2) {
            return n;
        }

        int prev1 = 1; // n - 2
        int prev2 = 2;  //n - 1
        int result = 0;

        for(int i = 3; i <= n; i++) {
            result = prev1 + prev2;
            prev1 = prev2;
            prev2 = result;
        }

        return result;
    }
};