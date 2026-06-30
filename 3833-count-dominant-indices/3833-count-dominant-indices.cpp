class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[n-1];

        int ans = 0;
        for(int i = n-2; i >= 0; i--){
            double avg = sum/(n - i - 1);
            if(nums[i] > avg) ans++;

            sum += nums[i];
        }

        return ans;
    }
};