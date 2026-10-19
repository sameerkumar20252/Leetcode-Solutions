class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int targetCount = 0;
        int mn  = 0;
        for(int x : nums) {
            if(x == target) {
                targetCount++;
            } else if(x < target) {
                mn++;
            }
        }

        vector<int> ans(targetCount);
        iota(ans.begin(), ans.end(), mn);

        return ans;
    }
};