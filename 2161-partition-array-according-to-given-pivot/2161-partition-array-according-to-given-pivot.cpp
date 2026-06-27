class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int idx = 0;

        for(int x : nums) {
            if(x < pivot) {
                ans[idx++] = x;
            }
        }

        for(int x : nums) {
            if(x ==  pivot) {
                ans[idx++] = x;
            }
        }

        for(int x : nums) {
            if(x > pivot) {
                ans[idx++] = x;
            }
        }

        return ans;
    }
};