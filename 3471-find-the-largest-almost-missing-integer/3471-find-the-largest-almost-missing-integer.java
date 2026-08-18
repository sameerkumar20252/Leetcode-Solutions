class Solution {
    public int largestInteger(int[] nums, int k) {
        int[] freq = new int[51];
        Set<Integer> s = new HashSet<>();

        for(int i = 0; i <= nums.length - k; i++) {
            for(int j = 0; j < k; j++) {
                s.add(nums[i + j]);
            }
            for(int x : s) {
                freq[x]++;
            }
            s.clear();
        }

        for(int i = 50; i >= 0; i--) {
            if(freq[i] == 1) {
                return i;
            }
        }

        return -1;
    }
}