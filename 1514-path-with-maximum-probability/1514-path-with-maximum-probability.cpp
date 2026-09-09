class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, succProb[i]});
            adj[v].push_back({u, succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        vector<double> prob(n, 0.0);
        prob[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(pq.size() > 0) {
            auto[p, u] = pq.top();
            pq.pop();

            if(p < prob[u]) continue;

            for(auto[v, wt] : adj[u]) {
                if(prob[v] < prob[u] * wt) {
                    prob[v] = prob[u] * wt;
                    pq.push({prob[v], v});
                }
            }
        }

        return prob[end_node];
    }
};