class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
            m[nums[i]]++;
        }
        if(m.size() == k){
            ans =  sum;
        }
        for(int i = k; i < nums.size(); i++){
            m[nums[i-k]]--;
            m[nums[i]]++;
            if(m[nums[i-k]] == 0){
                m.erase(nums[i-k]);
            }
            sum = sum - nums[i-k];
            sum = sum + nums[i];
            if((m.size() == k) && (ans < sum)){
                ans = sum;
            }
        }
        return ans;
    }
};