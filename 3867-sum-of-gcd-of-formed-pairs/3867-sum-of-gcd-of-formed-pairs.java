class Solution {
    long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public long gcdSum(int[] nums) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        long[] prefixGcd = new long[n];
        for(int i = 0; i < n; i++) {
            mx = Math.max(nums[i], mx);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        Arrays.sort(prefixGcd);

        int i = 0, j = n - 1;
        long sum = 0;
        while(i < j) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;j--;
        }
        return sum;
    }
}