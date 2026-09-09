class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path) {
        if(u == graph.size() - 1) {
            ans.push_back(path);
            return;
        }
        for(int v : graph[u]) {
            path.push_back(v);
            dfs(v, graph, ans, path);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;

        path.push_back(0);
        dfs(0, graph, ans, path);

        return ans;
    }
};