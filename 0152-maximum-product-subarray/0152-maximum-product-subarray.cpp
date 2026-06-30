class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1;
        int ans = nums[0];

        for(int i = 0; i < nums.size(); i++){
            product = 1;
            for(int j = i; j < nums.size(); j++){
                product *= nums[j];
                ans = max(product, ans);
            }
        }
        return ans;
    }
};