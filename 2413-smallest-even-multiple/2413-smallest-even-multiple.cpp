class Solution {
public:
    int smallestEvenMultiple(int n) {
        int ans = n;
        while(ans % n != 0 || ans % 2 != 0) {
            ans += n;
        }

        return ans;
    }
};