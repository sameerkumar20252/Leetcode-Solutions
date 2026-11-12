class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int ans = 1;

        //check strictly increasing
        int inc = 1;

        for(int i = 0; i < n; i++) {
            inc = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] > nums[j-1]) {
                    inc++;
                    ans = Math.max(ans, inc);
                } else {
                    inc = 1;
                    break;
                }
            }
        }

        //check strictly decreasing
        int dec = 1;

        for(int i = 0; i < n; i++) {
            dec = 1;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[j-1]) {
                    dec++;
                    ans = Math.max(ans, dec);
                } else {
                    dec = 1;
                    break;
                }
            }
        }

        return ans;
    }
}