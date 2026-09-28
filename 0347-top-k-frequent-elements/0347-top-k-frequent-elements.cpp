class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //usimg bucket sort
        unordered_map<int,int> m;
        for(int i : nums) {
            m[i]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for(auto& e : m) {
            int idx = e.second;
            int val = e.first;
            bucket[idx].push_back(val);
        }
        vector<int> ans;

        for(int i = n; i >= 0; i--) {
            for(int v : bucket[i]) {
                ans.push_back(v);
                if(ans.size() == k) break;
            }
            if(ans.size() == k) break;
        }

        return ans;
    }
};