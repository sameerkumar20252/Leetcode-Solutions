class Solution {
public:
    void mark_Suspicious(int u, vector<vector<int>>& adj, vector<bool>& mark) {
        mark[u] = false;

        for(int v : adj[u]) {
            if(mark[v]) {
                mark_Suspicious(v, adj, mark);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //make adjacent list
        vector<vector<int>> adj(n);
        for(auto& e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        //mark suspicious methods
        vector<bool> mark(n, true);
        mark_Suspicious(k, adj, mark);

        //remove invoked methods
        for(auto& e : invocations) {
            if(mark[e[0]] && !mark[e[1]]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};