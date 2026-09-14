class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<int> dis(n, INT_MAX);
        vector<vector<pair<int,pair<int,int>>>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], {e[2], e[3]}});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        dis[0] = 0;

        while(pq.size() > 0) {
            auto[t, u] = pq.top();
            pq.pop();

            if(t > dis[u]) continue;

            for(auto[v, time] : adj[u]) {
                int wt = 1;
                if(t < time.first) {
                    wt += (time.first - t);
                } else if(t > time.second) {
                    continue;
                }
                if(dis[v] > wt + dis[u]) {
                    dis[v] = wt + dis[u];
                    pq.push({dis[v], v});
                }
            }
        }

        return dis[n-1] == INT_MAX ? -1 : dis[n-1];
    }
};