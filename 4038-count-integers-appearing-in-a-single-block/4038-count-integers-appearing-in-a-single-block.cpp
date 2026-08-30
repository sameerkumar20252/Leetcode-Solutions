class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<vector<int>> pos(100);
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            int idx = nums[i] - 1;
            pos[idx].push_back(i);
        }

        for(int i = 0; i < 100; i++) {
            if(pos[i].size() > 0) {
                bool flag = true;
                for(int x = 1; x < pos[i].size(); x++) {
                    if(pos[i][x] - pos[i][x-1] > 1) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    ans++;
                }
            }
        }

        return ans;
    }
};