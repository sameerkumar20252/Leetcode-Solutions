class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int>ans(2,-1);
        int prev_prod = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum = nums[i] + nums[j];

                if(sum == target && nums[i] > nums[j])
                {
                    int prod = nums[i] * nums[j];

                    if(prev_prod < prod)
                    {
                        prev_prod = prod;
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }

        return ans;
        
    }
};