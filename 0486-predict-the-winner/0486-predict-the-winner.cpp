class Solution {
public:
    // bool p1 = true, p2 = false;
    bool findWinner(vector<int>& nums, int i, int j, int play1, int play2, bool p1, bool p2) {
        if(j - i <= 1) {
            int mx = nums[i];
            int mn = nums[j];
            if(mx < mn) {
                mx = nums[j];
                mn = nums[i];
            }
            if(p1) {
                return play1 + mx >= play2 + mn;
            }
            // p2 = false, p1 = true;
            return play1 + mn >= play2 + mx;
        }
        if(p1) {
            bool x = findWinner(nums, i + 1, j, play1 + nums[i], play2, false, true);
            // p1 = false; p2 = true;
            bool y = findWinner(nums, i, j - 1, play1 + nums[j], play2, false, true);
            if(x || y) return true;
            // p1 = false; p2 = true;
        }
        else {
            bool x = findWinner(nums, i + 1, j, play1, play2 + nums[i], true, false);
            // if(x) return true;
            // p2 = false, p1 = true;
            bool y = findWinner(nums, i, j - 1, play1, play2 + nums[j], true, false);
            return x && y;
            // p2 = false, p1 = true;
        }
        return false;
    }

    bool predictTheWinner(vector<int>& nums) {
        // int i = 0, j = nums.size() - 1;
        // int play1 = 0, play2 = 0;
        int n = nums.size();
        if(n == 1) return true;

        return findWinner(nums, 0, n - 1, 0, 0, true, false);
    }
};