class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> ans(n,-1);
        // stack<int> s;
        // for(int i=2*n-1;i>=0;i--){
        //     while(s.size()>0 && nums[s.top()]<=nums[i%n]){
        //         s.pop();
        //     }
        //     ans[i%n] = s.empty()?-1:nums[s.top()];
        //     s.push(i%n);
        // }
        // return ans;
        stack<int> s;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            s.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }else{
                ans[i]=s.top();
            }
            s.push(nums[i]);
        }
        return ans;
    }
};