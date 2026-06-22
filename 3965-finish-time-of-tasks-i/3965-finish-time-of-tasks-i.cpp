class Solution {
public:
    long long dfs(int src, vector<int> adj[], vector<int>& base, vector<bool>& vis) {
        long long latest = LLONG_MIN;
        long long earliest = LLONG_MAX;
        vis[src] = true;

        if(adj[src].size() == 0) {
            return base[src];
        }

        for(int v : adj[src]) {
            long long time;
            if(!vis[v]) {
                time = dfs(v, adj, base, vis);
            }
            latest = max(latest, time);
            earliest = min(earliest, time);
        }

        long long own = (latest - earliest) + (long long)base[src];
        return latest + own;
    }
    
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<int> adj[n];
        vector<bool> vis(n, false);
        
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        return dfs(0, adj, baseTime, vis);
    }
};