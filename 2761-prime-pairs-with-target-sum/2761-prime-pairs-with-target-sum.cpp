class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        if(n <= 2) return ans;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i = 0; i <= n; i++) {
            if(isPrime[i]) {
                int tar = n - i;
                if(isPrime[tar]) {
                    ans.push_back({i, tar});
                    isPrime[tar] = false;
                }
                isPrime[i] = false;
            }
        }

        return ans;
    }
};