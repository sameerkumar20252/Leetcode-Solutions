class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int st = 0, end = nums.size() - 1;
        long long ans = 0;

        while(st < end) {
            ans += (nums[end] * nums[end]);
            ans -= (nums[st] * nums[st]);
            end--;
            st++;
        }

        if(st == end) {
            ans += (nums[end] * nums[end]);
        }

        return ans;
    }
};