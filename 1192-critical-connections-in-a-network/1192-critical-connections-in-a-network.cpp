class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<vector<int>>& adj, vector<vector<int>>& cc) {
        dt[u] = low[u] = ++time;

        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];

            if(dt[v] == -1) {  //case1 - unvisited
                dfs(v, u, adj, cc);
                //update low[u]
                low[u] = min(low[u], low[v]);
                //check bridge
                if(low[v] > dt[u]) {
                    cc.push_back({u, v});
                }
            } else if(v != parU) {  // case 2 - visited & not parent
                //update low[u]
                low[u] = min(low[u], dt[v]);
            }
            //case 3 - visited but parent ignore
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //make adjacent list
        vector<vector<int>> adj(n);
        for(auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dt.resize(n, -1);
        low.resize(n);
        vector<vector<int>> bridges;

        for(int i = 0; i < n; i++) {
            if(dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }

        return bridges;
    }
};