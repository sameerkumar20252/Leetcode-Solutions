class Solution {
public:
    int m[26];
    int dfs(vector<vector<int>>& adj, int u, vector<int>& ans) {
        for(int v : adj[u]) {
            ans[u] += dfs(adj, v, ans);
        }
        ans[u]++;
        return ans[u];
    }

      void solve(vector<vector<int>>& adj, vector<vector<int>>& newAdj,
               int u, vector<int>& ans, string& s, int par) {

        int node = m[s[u] - 'a'];

        int newPar = (node == -1) ? par : node;

        if(par != -1) {
            newAdj[newPar].push_back(u);
        }

        m[s[u] - 'a'] = u;

        for(int v : adj[u]) {
            solve(adj, newAdj, v, ans, s, u);
        }

        m[s[u] - 'a'] = node;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), newAdj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> ans(n, 0);
        fill(m, m + 26, -1);

        solve(adj, newAdj, 0, ans, s, -1);

        dfs(newAdj, 0, ans);

        return ans;
    }
};