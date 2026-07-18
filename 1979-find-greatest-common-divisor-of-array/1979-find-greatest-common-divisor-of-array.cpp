class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MAX, b = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            a = min(nums[i], a);
            b = max(nums[i], b);
        }

        while(b > 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }

        return a;
    }
};