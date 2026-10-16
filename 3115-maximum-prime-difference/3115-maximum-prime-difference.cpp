class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<bool> isPrime(101, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i * i <= 100; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= 100; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int first = -1, last = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(isPrime[nums[i]]) {
                last = i;
                if(first == -1) {
                    first = i;
                }
            }
        }

        return last - first;
    }
};