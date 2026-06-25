class Solution {
public:
    void getSubset(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& subset){
        if(i==nums.size()){
            subset.push_back({ans});
            return;
        }
        //inclusion
        ans.push_back(nums[i]);
        getSubset(nums,ans,i+1,subset);

        //exclusion
        ans.pop_back();
        getSubset(nums,ans,i+1,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ans;
        getSubset(nums,ans,0,subset);
        return subset;
    }
};