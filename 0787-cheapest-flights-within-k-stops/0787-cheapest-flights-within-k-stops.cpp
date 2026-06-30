class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& e : flights) {
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        queue<tuple<int,int,int>> Q;
        Q.push({src, 0, -1});

        while(Q.size() > 0) {
            auto [u, cost, steps] = Q.front();
            Q.pop();

            for(auto& e : adj[u]) {
                if(dis[e.first] > cost + e.second && steps + 1 <= k) {
                    dis[e.first] = cost + e.second;
                    Q.push({e.first, dis[e.first], steps+1});
                }
            }
        }

        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};