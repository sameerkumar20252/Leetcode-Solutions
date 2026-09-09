class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        if(n < 1000) {
            return 0;
        }

        if(n < 1000000) {
            ans = n - 1000 + 1;
            return ans;
        } else if(n < 1000000000) {
            ans = 999000 + (n - 1000000 + 1)*2;
            return ans;
        } else if(n < 1000000000000) {
            ans = 999000 + 999000000*2 + (n - 1000000000 + 1)*3;
            return ans;
        } else if(n < 1000000000000000) {
            ans = 999000 + 999000000*2 + 999000000000*3 + (n - 1000000000000 + 1)*4;
            return ans;
        }

        ans = 999000 + 999000000*2 + 999000000000*3 + 999000000000000*4 + 5;
        return ans;
    }
};