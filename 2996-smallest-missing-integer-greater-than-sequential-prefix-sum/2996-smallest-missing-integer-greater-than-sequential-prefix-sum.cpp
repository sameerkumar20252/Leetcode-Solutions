class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums) {
            s.insert(x);
        }

        int sum = nums[0];
        // int ans = nums[0];
        int i = 1;
        while(i < nums.size() && nums[i-1]+1 == nums[i]) {
            sum += nums[i++];
        }

        while(s.count(sum)) {
            sum++;
        }

        return sum;
    }
};