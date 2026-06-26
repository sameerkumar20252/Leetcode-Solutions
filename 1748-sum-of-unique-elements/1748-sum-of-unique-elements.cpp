class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
          unordered_map<int,int> s;
          int sum=0;
         for(int i=0;i<nums.size();i++){
             if(s.find(nums[i])==s.end()){
                sum+=nums[i];
                s[nums[i]]=1;
             }else{
                if(s[nums[i]]==1){
                   sum=sum-nums[i];
                   s[nums[i]]=0;
                }
             }
         }
        return sum;
    }
};