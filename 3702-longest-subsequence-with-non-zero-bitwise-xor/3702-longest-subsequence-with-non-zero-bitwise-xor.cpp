class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        bool allzero=true;
        for(int i:nums){
            ans^=i;
            if(i != 0){
                allzero=false;
            }
        }
        if(ans != 0){
            return nums.size();
        }
        if(!allzero){
            return nums.size()-1;
        }
        return ans;
    }
};