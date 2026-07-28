class Solution {
public:
    int largestInteger(int n, int s) {
        int num = pow(10, n) - 1;

        while(num >= 0) {
            int x = num;
            int sum = 0;
            while(x > 0) {
                int r = x % 10;
                sum += r;
                x /= 10;
            }
            if(sum == s) {
                return num;
            }
            num--;
        }

        return -1;
    }
};