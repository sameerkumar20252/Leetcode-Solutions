class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        if(n >= 1) isPrime[0] = false;
        if(n >= 2) isPrime[1] = false;

        for(long long i = 2; i < n; i++) {
            if(isPrime[i]) {
                for(long long j = i * i; j < n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }

        int ans = 0;
        for(bool x : isPrime) {
            if(x) ans++;
        }

        return ans;
    }
};