class Solution {
public:
    void dfs(int i, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[i] = true;

        for(int j = 0; j < graph.size(); j++) {
            if(graph[i][j] && !vis[j]) {
                dfs(j, graph, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size();
        int prov = 0;
        vector<bool> vis(n, false);


        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                dfs(j, graph, vis);
                prov++;
            }
        }

        return prov;
    }
};