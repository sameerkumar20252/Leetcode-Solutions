class Solution {
    public int maximumLengthSubstring(String s) {
        int[] hash = new int[26];
        int n = s.length();
        int ans = 0;

        int i = 0;
        for(int j = 0; j < n; j++) {
            int idx = s.charAt(j) - 'a';
            hash[idx]++;
            if(hash[idx] > 2) {
                ans = Math.max(ans, j - i);
                while(s.charAt(i) != s.charAt(j)) {
                    hash[s.charAt(i) - 'a']--;
                    i++;
                }
                hash[s.charAt(i) - 'a']--;
                i++;
            }
        }

        ans = Math.max(ans, n - i);

        return ans;
    }
}