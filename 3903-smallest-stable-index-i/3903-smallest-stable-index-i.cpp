class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minEle(n);

        int maxVal = INT_MIN;

        int minVal = INT_MAX;

        for(int i = n - 1; i >= 0; i--) {
            minVal = min(minVal, nums[i]);
            minEle[i] = minVal;
        }

        int ans = -1;

        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            if((maxVal - minEle[i]) <= k) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};