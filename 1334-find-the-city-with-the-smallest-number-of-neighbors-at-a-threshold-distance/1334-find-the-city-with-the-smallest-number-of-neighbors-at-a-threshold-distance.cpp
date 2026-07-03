class Solution {
public:
    vector<int> Dijkstra(int src, vector<vector<pair<int,int>>>& adj, int thr) {
        int n = adj.size();
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > pq;

        vector<int> dis(n, INT_MAX);

        dis[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dis[u]) continue;

            for(auto &[v, wt] : adj[u]) {
                if(d + wt < dis[v]) {
                    dis[v] = d + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans = 0;
        int city = INT_MAX;

        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});

        }

        for(int i = 0; i < n; i++) {
            vector<int> dis = Dijkstra(i, adj, distanceThreshold);
            int temp = 0;
            for(int x : dis) {
                if(x <= distanceThreshold) {
                    temp++;
                }
            }
            if(temp <= city) {
                city = temp;
                ans = i;
            }
        }

        return ans;
    }
};