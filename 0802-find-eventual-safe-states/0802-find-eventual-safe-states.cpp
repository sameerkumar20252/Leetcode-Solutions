class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& rec, vector<bool>& loop) {
        vis[src] = true;
        rec[src] = true;

        bool isLoop = false;

        for(int v : graph[src]) {
            if(!vis[v]) {
                if(dfs(v, graph, vis, rec, loop)) {
                    loop[src] = true;
                    rec[src] = false;
                    return true;
                }
            } else if(rec[v]){
                loop[src] = true;
                rec[src] = false;
                return true;
            } else if(loop[v]) {
                loop[src] = true;
                rec[src] = false;
                return true;
            }
        }

        rec[src] = false;
        return isLoop;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> vis(V, false), rec(V, false), loop(V, false);

        for(int i = 0; i < V; i++) {
            dfs(i, graph, vis, rec, loop);
        }
        vector<int> ans;

        for(int i = 0; i < V; i++) {
            if(!loop[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};