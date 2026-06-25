class Solution {
public:
    void getSubset(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& subset){
        if(i==nums.size()){
            subset.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getSubset(nums,ans,i+1,subset);

        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        getSubset(nums,ans,idx,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subset;
        vector<int> ans;
        getSubset(nums,ans,0,subset);
        return subset;
    }
};