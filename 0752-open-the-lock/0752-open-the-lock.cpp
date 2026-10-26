class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int V = 10000;
        string src = "0000";
        unordered_set<string> s;
        for(const auto& d : deadends) {
            s.insert(d);
        }
        if(s.count("0000")) return -1;

        queue<pair<string, int>> Q; //{node, dis}
        Q.push({src, 0});
        vector<bool> vis(V, false);
        vis[0] = true;

        while(Q.size() > 0) {
            int size = Q.size();

            for(int i = 0; i < size; i++) {
                auto[u, count] = Q.front();
                Q.pop();
                if(u == target) return count;
                for(int j = 0; j < 4; j++) {
                    string s1 = u;
                    string s2 = u;
                    //+1
                    if(s1[j] == '9') {
                        s1[j] = '0';
                    } else {
                        s1[j] += 1;
                    }
                    int idx1 = stoi(s1);
                    if(!s.count(s1) && !vis[idx1]) {
                        vis[idx1] = true;
                        Q.push({s1, count+1});
                    }

                    //-1
                    if(s2[j] == '0') {
                        s2[j] = '9';
                    } else {
                        s2[j] -= 1;
                    }
                    int idx2 = stoi(s2);
                    if(!s.count(s2) && !vis[idx2]) {
                        vis[idx2] = true;
                        Q.push({s2, count+1});
                    }
                }
            }
        }

        return -1;
    }
};