class Solution {
public:
    int nodes;
    int dfs(int u, vector<vector<int>>& adj, long long& ans, vector<long long>& vec) {
        int sum = 0;
        long long score = 1;
        for(int v : adj[u]) {
            int val = dfs(v, adj, ans, vec);
            if(val > 0) {
                score *= val;
            }
            sum += val;
        }
        int rem = (nodes - sum - 1);
        score = rem > 0 ? score * rem : score;
        ans = max(ans, score);
        vec[u] = score;

        return sum + 1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        nodes = parents.size();
        vector<vector<int>> adj(nodes);
        vector<long long> vec(nodes);

        for(int i = 1; i < nodes; i++) {
            adj[parents[i]].push_back(i);
        }
        long long ans = INT_MIN;
        dfs(0, adj, ans, vec);
        int count = 0;

        for(int i = 0; i < nodes; i++) {
            if(vec[i] == ans) {
                count++;
            }
        }

        return count;
    }
};