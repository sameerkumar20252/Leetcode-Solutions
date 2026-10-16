class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;

        vector<int> isPrime(1001, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i * i <= 1000; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] >= nums[i+1]) {
                int prev = nums[i];
                int diff = nums[i] - nums[i+1];
                for(int p = diff + 1; p < nums[i]; p++) {
                    if(isPrime[p]) {
                        nums[i] -= p;
                        break;
                    }
                }
                if(nums[i] == prev) return false;
            }
        }

        return true;
    }
};