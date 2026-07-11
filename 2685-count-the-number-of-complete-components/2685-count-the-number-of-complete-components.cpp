class Solution {
public:
    void dfs(int src, vector<vector<int>>& adj, vector<bool>& vis, int& V, int& edge) {
        vis[src] = true;

        for(int v : adj[src]) {
            edge++;
            if(!vis[v]) {
                V++;
                dfs(v, adj, vis, V, edge);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //--------------------By DFS---------------------------//
        int components = 0;

        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                int V = 1, edge = 0;
                dfs(i, adj, vis, V, edge);
                if(edge == (V*V - V)) {
                    components++;
                }
            }
        }

        return components;
    }
};