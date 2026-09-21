class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);

        int m = primes.size();
        vector<int> idx(m, 0);
        vector<long long> ith(m);
        dp[0] = 1;

        for(int i = 1; i < n; i++) {
            long long mn = LLONG_MAX;
            for(int j = 0; j < m; j++) {
                long long mul = dp[idx[j]] * primes[j];
                ith[j] = mul;
                mn = min(mn, mul);
            }
            dp[i] = mn;
            for(int j = 0; j < m; j++) {
                if(mn == ith[j]) {
                    idx[j]++;
                }
            }
        }

        return dp[n-1];
    }
};