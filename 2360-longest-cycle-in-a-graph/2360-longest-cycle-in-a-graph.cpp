class Solution {
public:
    int ans = -1;
    void dfs(int src, vector<int>& edges, vector<bool>& vis, vector<pair<bool, int>>& rec) {
        vis[src] = true;
        rec[src].first = true;
        int len = rec[src].second;

        int v = edges[src];

        if(v == -1) {
            rec[src].first = false;
            rec[src].second = 0;
            return;
        }
        if(!vis[v]) {
            rec[v].second = len + 1;
            dfs(v, edges, vis, rec);
        } else if(rec[v].first) {
            int x = len - rec[v].second + 1;
            ans = max(ans, x);
        }

        rec[src].first = false;
        rec[src].second = 0;
    }

    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<bool> vis(V, false);
        vector<pair<bool, int>> rec(V, {false, 0});

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                rec[i].second = 1;
                dfs(i, edges, vis, rec);
            }
        }

        return ans;
    }
};