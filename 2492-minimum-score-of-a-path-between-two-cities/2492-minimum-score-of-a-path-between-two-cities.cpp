class Solution {
public:
    void dfs(int src, vector<vector<pair<int,int>>>& adj, vector<bool>& vis, int& ans) {
        vis[src] = true;

        for(auto& [v, wt] : adj[src]) {
            ans = min(ans, wt);

            if(!vis[v]) {
                dfs(v, adj, vis, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int minEdge = INT_MAX;
        vector<vector<pair<int,int>>> adj(n);

        for(auto& e : roads) {
            adj[e[0]-1].push_back({e[1]-1, e[2]});
            adj[e[1]-1].push_back({e[0]-1, e[2]});
        }

        vector<bool> vis(n, false);

        dfs(0, adj, vis, minEdge);

        return minEdge;
    }
};