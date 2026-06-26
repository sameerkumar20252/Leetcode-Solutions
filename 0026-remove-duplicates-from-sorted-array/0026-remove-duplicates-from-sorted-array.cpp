class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size(),a=0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
                nums[a++]=nums[i];
            }
        }
        return s.size();
    }
};