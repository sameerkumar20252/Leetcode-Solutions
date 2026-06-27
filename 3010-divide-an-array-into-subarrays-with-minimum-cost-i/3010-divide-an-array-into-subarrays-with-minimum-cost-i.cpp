class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int n = nums.size();
        int a = nums[1], b = nums[2];
        int i = 2, j = 3;
        while(j < n){
            if(nums[j] <= b){
                a = min(a, b);
                b = nums[j];
                a = min(nums[i], a);
            }else{
                if(nums[i] <= a){
                    int x = nums[i] + nums[j];
                    if(x < a+b){
                        a = nums[i];
                        b = nums[j];
                    }
                }
                if(a+b > nums[j]+b){
                    a = b;
                    b = nums[j];
                }
            }
            i++, j++;
        }
        return ans + a + b;
    }
};