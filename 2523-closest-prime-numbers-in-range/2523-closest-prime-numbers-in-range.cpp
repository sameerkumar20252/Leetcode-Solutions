class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans(2, -1);
        if(right <= 2) return ans;

        vector<int> isPrime(right + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(long long i = 2; i * i <= right; i++) {
            if(isPrime[i]) {
                for(long long j = i * i; j <= right; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        int diff = INT_MAX;
        int prev = -1;
        for(int i = left; i <= right; i++) {
            if(isPrime[i]) {
                if(prev == -1) {
                    prev = i;
                } else {
                    if((i - prev) < diff) {
                        ans[0] = prev;
                        ans[1] = i;
                        diff = i - prev;
                    }
                    prev = i;
                }
            }
        }

        if(ans[0] == -1 || ans[1] == -1) return {-1, -1};
        return ans;
    }
};