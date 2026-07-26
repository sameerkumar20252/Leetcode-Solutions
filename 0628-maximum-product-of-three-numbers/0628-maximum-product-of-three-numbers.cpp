class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int fmx = INT_MIN, smx = INT_MIN, tmx = INT_MIN;
        int fmn = INT_MAX, smn = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(nums[i] > fmx) {
                tmx = smx;
                smx = fmx;
                fmx = nums[i];
            }
            else if (nums[i] > smx) {
                tmx = smx;
                smx = nums[i];
            }
            else if(nums[i] > tmx){
                tmx = nums[i];
            }

            if(nums[i] < fmn) {
                smn = fmn;
                fmn = nums[i];
            }
            else if(nums[i] < smn) {
                smn = nums[i];
            }
        }

        int mx1 = fmn * smn * fmx;
        int mx2 = fmx * smx * tmx;

        return max(mx1, mx2);
    }
};