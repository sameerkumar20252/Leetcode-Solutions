class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] freq = new int[256];

        int i = 0;
        int n = s.length();
        int ans = Integer.MIN_VALUE;

        for(int j = 0; j < n; j++) {
            freq[s.charAt(j)]++;

            if(freq[s.charAt(j)] > 1) {
                ans = Math.max(ans, j - i);
                while(freq[s.charAt(j)] > 1) {
                    freq[s.charAt(i)]--;
                    i++;
                }
            }
        }

        ans = Math.max(ans, n - i);

        return ans;
    }
}