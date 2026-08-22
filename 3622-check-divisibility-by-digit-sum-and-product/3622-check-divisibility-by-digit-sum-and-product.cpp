class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1;
        int val = n;

        while(n > 0) {
            int r = n % 10;
            sum += r;
            pro *= r;
            n /= 10;
        }

        return val % (sum + pro) == 0;
    }
};