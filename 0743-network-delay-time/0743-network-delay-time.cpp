class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;

        vector<vector<pair<int,int>>> adj(n);

        for(auto& e : times) {
            adj[e[0]-1].push_back({e[1]-1,e[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k-1});

        while(pq.size() > 0) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dis[u]) continue;

            for(auto& e : adj[u]) {
                if(dis[e.first] > dis[u] + e.second) {
                    dis[e.first] = dis[u] + e.second;
                    pq.push({dis[e.first], e.first});
                }
            }
        }

        int ans = INT_MIN;

        for(int x : dis) {
            if(x == INT_MAX) return -1;
            ans = max(ans, x);
        }

        return ans;
    }
};