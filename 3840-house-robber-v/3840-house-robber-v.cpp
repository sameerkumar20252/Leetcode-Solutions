class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long money = 0;
        long long even = nums[0], odd = 0;
        int idx = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(colors[i] == colors[i-1]){
                int num = i - idx;
                if(num % 2 == 0){
                    even += nums[i];
                }else{
                    odd += nums[i];
                }
            }else{
                money += max(even, odd);
                even = nums[i];
                odd = 0;
                idx = i;
            }
        }

        money += max(even, odd);

        return money;
    }
};