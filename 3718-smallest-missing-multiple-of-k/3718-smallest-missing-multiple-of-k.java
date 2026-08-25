class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();

        for(int x : nums) {
            s.add(x);
        }

        int ans = k;
        while(s.contains(ans)) {
            ans += k;
        }

        return ans;
    }
}