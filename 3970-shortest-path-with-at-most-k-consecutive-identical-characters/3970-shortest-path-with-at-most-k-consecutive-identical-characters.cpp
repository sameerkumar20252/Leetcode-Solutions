class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }

        using T = pair<int, pair<int,int>>; //{weight, {node, labels}}
        priority_queue<T, vector<T>, greater<T>> Q;
        vector<vector<int>> dis(n, vector<int>(k + 1, INT_MAX));
        dis[0][1] = 0;

        Q.push({0, {0, 1}});

        while(Q.size() > 0) {
            auto[d, node] = Q.top();
            Q.pop();

            int u = node.first;
            int cons = node.second;

            if(d != dis[u][cons]) continue;

            if(u == n - 1) return d;

            for(auto[v, w] : adj[u]) {
                int x = cons;
                if(labels[v] == labels[u]) x++;
                else x = 1;
                if(x > k) continue;

                if(dis[v][x] > d + w) {
                    dis[v][x] = d + w;
                    Q.push({dis[v][x], {v, x}});
                }
            }
        }


        return dis[n-1][k] == INT_MAX ? -1 : dis[n-1][k];
    }
};