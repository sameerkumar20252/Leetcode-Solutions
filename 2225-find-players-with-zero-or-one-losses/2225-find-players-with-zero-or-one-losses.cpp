class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> m;
        set<int> s;

        for(auto& match : matches) {
            int win = match[0];
            int lost = match[1];

            m[lost]++;
            if(!m.count(win)) {
                s.insert(win);
            }
            if(s.count(lost)) {
                s.erase(lost);
            }
        }

        vector<int> temp1;
        for(int x : s) {
            temp1.push_back(x);
        }
        vector<int> temp2;
        for(auto& p : m) {
            if(p.second == 1) {
                temp2.push_back(p.first);
            }
        }
        sort(temp2.begin(), temp2.end());
        ans[0] = temp1;
        ans[1] = temp2;

        return ans;
    }
};