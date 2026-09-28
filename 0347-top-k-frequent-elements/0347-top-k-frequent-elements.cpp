class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //first using map
        unordered_map<int,int> m;
        for(int i : nums) {
            m[i]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& p : m) {
            pq.push({p.second, p.first});
        }

        vector<int> ans;
        while(k--) {
            auto val = pq.top();
            pq.pop();
            ans.push_back(val.second);
        }

        return ans;
    }
};