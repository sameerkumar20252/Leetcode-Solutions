class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> m;

        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        int ans = 0;

        for(auto[k, v] : m) {
            if(v.size() >= 3) {
                int gap = abs(v[1] - v[0]);
                ans++;
                for(int i = 2; i < v.size(); i++) {
                    if(abs(v[i] - v[i-1]) != gap) {
                        ans--;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};