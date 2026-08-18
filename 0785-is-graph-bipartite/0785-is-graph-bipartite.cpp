class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, int parColor, vector<int>& color) {
        color[src] = parColor == 1 ? 0 : 1;

        for(int v : graph[src]) {
            if(color[v] == -1) {
                if(dfs(v, graph, color[src], color)) {
                    return true;
                }
            } else if(color[v] == color[src]) {
                return true;
            }
        }

        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(dfs(i, graph, 1, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};