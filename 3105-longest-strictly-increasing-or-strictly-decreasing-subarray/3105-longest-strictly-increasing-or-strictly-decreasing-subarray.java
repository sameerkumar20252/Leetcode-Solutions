class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int ans = 1;
        int inc = 0;
        int dec = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                ans = Math.max(ans, i - inc + 1);
            } else {
                inc = i;
            }

            if(nums[i] < nums[i-1]) {
                ans = Math.max(ans, i - dec + 1);
            } else {
                dec = i;
            }
        }

        return ans;
    }
}