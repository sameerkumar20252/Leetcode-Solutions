class Solution {
    public int findGCD(int[] nums) {
        int a = Integer.MAX_VALUE, b = Integer.MIN_VALUE;

        for(int x : nums) {
            a = Math.min(a, x);
            b = Math.max(b, x);
        }

        while(b > 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }

        return a;
    }
}