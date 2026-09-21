class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n);

        int m = primes.size();
        vector<int> idx(m, 0);
        // vector<long long> ith(m);
        using T = pair<long long,int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        dp[0] = 1;

        for(int i = 0; i < m; i++) {
            pq.push({(long long)primes[i], i});
        }

        for(int i = 1; i < n; i++) {
            long long mn = pq.top().first;
            dp[i] = mn;

            while(!pq.empty() && pq.top().first == mn) {
                int j = pq.top().second;
                pq.pop();
                idx[j]++;
                pq.push({dp[idx[j]] * primes[j], j});
            }

        }

        return dp[n-1];
    }
};