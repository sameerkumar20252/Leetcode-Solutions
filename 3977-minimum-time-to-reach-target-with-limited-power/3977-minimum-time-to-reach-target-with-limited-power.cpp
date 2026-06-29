class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        if(source == target) {
            return {0, power};
        }

        vector<vector<pair<int,int>>> adj(n);

        for(auto& e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<long long> ans(2);
        ans[0] = LLONG_MAX;
        ans[1] = -1;
        vector<vector<long long>> dist(n , vector<long long>(power + 1, LLONG_MAX));
        priority_queue<tuple<long long,int,int>,vector<tuple<long long, int,int>>, greater<>> pq;
        dist[source][power] = 0;

        pq.push({0, source, power});  //{step, node, remainingPower}

        while(pq.size() > 0) {
            auto [dis, u, p] = pq.top();
            pq.pop();

            if(dis != dist[u][p]) continue;

            if(p < cost[u]) continue;

            int newP = p - cost[u];

            for(auto& [v, wt] : adj[u]) {
                long long newDis = dis + wt;

                if(newDis < dist[v][newP]) {
                    dist[v][newP] = newDis;
                    pq.push({newDis, v, newP});
                }
            }
        }

        for(int p = 0; p <= power; p++) {
            if(dist[target][p] < ans[0]) {
                ans[0] = dist[target][p];
                ans[1] = p;
            }
            else if(dist[target][p] == ans[0]) {
                ans[1] = max(ans[1], (long long)p);
            }
        }

        if(ans[0] == LLONG_MAX) {
            return {-1,-1};
        }

        return ans;
    }
};