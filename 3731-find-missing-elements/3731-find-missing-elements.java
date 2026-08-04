class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        int[] hash = new int[101];
        int mn = 101;
        int mx = 0;

        for(int i = 0; i < nums.length; i++) {
            hash[nums[i]]++;
            mn = Math.min(nums[i], mn);
            mx = Math.max(nums[i], mx);
        }

        List<Integer> ans = new ArrayList<>();

        for(int i = mn + 1; i < mx; i++) {
            if(hash[i] == 0) {
                ans.add(i);
            }
        }

        return ans;
    }
}