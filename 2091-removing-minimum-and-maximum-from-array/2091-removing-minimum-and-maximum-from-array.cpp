class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0, maxIdx = 0;
        int ans = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[minIdx]) {
                minIdx = i;
            }
            if(nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        int front = 0,  end = nums.size();
        int x = minIdx + 1 < end - minIdx ? minIdx + 1 : end - minIdx;
        int y = maxIdx + 1 < end - maxIdx ? maxIdx + 1 : end - maxIdx;

        if(x <= y) {
            if(minIdx + 1 <= end - minIdx) {
                ans += minIdx + 1;
                front = minIdx + 1;
            } else {
                ans += (end - minIdx);
                end = minIdx;
            }

            if(maxIdx - front + 1 <= end - maxIdx) {
                ans += maxIdx - front + 1;
            } else {
                ans += end - maxIdx;
            }
        } else {
            if(maxIdx + 1 <= end - maxIdx) {
                ans += maxIdx + 1;
                front = maxIdx + 1;
            } else {
                ans += (end - maxIdx);
                end = maxIdx;
            }

            if(minIdx - front + 1 <= end - minIdx) {
                ans += minIdx - front + 1;
            } else {
                ans += end - minIdx;
            }
        }

        return ans;
    }
};