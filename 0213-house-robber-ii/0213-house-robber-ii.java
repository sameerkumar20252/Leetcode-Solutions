class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if(n == 1) {
            return nums[0];
        }
        if(n == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int a = nums[0];
        int b1 = Math.max(nums[0], nums[1]);

        for(int i = 2; i < n - 1; i++) {
            int result = Math.max(b1, a + nums[i]);
            a = b1;
            b1 = result;
        }

        a = nums[1];
        int b2 = Math.max(nums[1], nums[2]);

        for(int i = 3; i < n; i++) {
            int result = Math.max(b2, a + nums[i]);
            a = b2;
            b2 = result;
        }

        return Math.max(b1, b2);
    }
}