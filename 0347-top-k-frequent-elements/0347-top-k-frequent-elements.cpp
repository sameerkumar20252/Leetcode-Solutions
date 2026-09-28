class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //first using map
        unordered_map<int,int> m;
        for(int i : nums) {
            m[i]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto& p : m) {
            pq.push({p.second, p.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            auto val = pq.top();
            ans.push_back(val.second);
            pq.pop();
        }

        return ans;
    }
};