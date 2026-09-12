class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        for(auto[k, v] : m) {
            if(v.size() == 3) {
                if(abs(v[1] - v[0]) == abs(v[2] - v[1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};