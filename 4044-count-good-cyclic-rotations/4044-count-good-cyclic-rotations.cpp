class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long sum1 = 0, sum2 = 0;
        int n = nums.size();
        int ans = 0;
        int i = 0, j = n/2;

        for(int i = 0; i < n; i++) {
            if(i < n/2) {
                sum1 += nums[i];
            }
            else {
                sum2 += nums[i];
            }
        }

        while(i < n) {
            sum1 -= nums[i];
            sum1 += nums[j];
            sum2 -= nums[j];
            sum2 += nums[i];

            if(sum1 > sum2) {
                ans++;
            }
            i++;
            j = (j + 1) % n;
        }

        return ans;
    }
};