class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        int n=nums.size();
        int count = 0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]=m[nums[i]]+1;
                if(m[nums[i]]>(n/k)){
                    return false;
                }
            }else{
                m[nums[i]]=1;
            }
        }
        return true;
    }
};