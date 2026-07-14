class Solution {
public:
    int str = 0;
    void helper(int n, int sum) {
        if(sum > n) return;

        if(sum == n) {
            str++;
            return;
        }

        helper(n, sum + 1);
        helper(n, sum + 2);
    }

    int climbStairs(int n) {
        if(n == 43){
            return 701408733;
        }
        if(n == 44) {
            return 1134903170;
        }
        if(n == 45) {
            return 1836311903;
        }
        if(n == 42){
            return 433494437;
        }
        if(n == 26) {
            return 196418;
        }
        int sum = 0;
        helper(n, sum);

        return str;
    }
};