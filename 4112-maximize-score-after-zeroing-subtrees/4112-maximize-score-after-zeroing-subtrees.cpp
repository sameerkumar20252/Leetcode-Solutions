class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& op, vector<int>& score) {
        if(adj[u].size() == 0) {
            return score[u];
        }

        int totalScore = 0;
        int minScore = INT_MAX;

        for(int v : adj[u]) {
            int temp = dfs(v, adj, op, score);
            totalScore += temp;
            if(temp < minScore) {
                minScore = temp;
            }
        }

        if(op[u] == 1) {
            totalScore -= minScore;
        } else {
            if(minScore < 0) {
                totalScore -= minScore;
            }
        }

        return totalScore + score[u];
    }


    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        return dfs(0, adj, op, score);
    }
};