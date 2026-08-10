class Solution {
public:
    long long ans = 0;
    void dfs(vector<vector<int>>& adj, int u, vector<int>& nums, int d, int h) {
        ans += 1LL * nums[u] * (h - d + 1);

        for(int v : adj[u]) {
            dfs(adj, v, nums, d + 1, h);
        }
    }

    //calculate height
    int bfs(vector<vector<int>>& adj) {
        queue<int> Q;
        Q.push(0);
        int h = 0;

        while(Q.size() > 0) {
            int n = Q.size();
            h++;

            for(int i = 0; i < n; i++) {
                int u = Q.front();
                Q.pop();

                for(int v : adj[u]) {
                    Q.push(v);
                }
            }
        }

        return h;
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        int h = bfs(adj);

        dfs(adj, 0, nums, 1, h);

        return ans;
    }
};