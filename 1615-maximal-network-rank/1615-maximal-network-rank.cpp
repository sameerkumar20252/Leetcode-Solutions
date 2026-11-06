class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> inDegree(n, 0);
        vector<vector<bool>> con(n, vector<bool>(n, false));

        for(auto& road : roads) {
            int u = road[0];
            int v = road[1];

            inDegree[u]++;
            inDegree[v]++;

            con[u][v] = true;
            con[v][u] = true;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                    int rank = inDegree[i] + inDegree[j] - con[i][j];
                ans = max(ans, rank);
                }
        }

        return ans;
    }
};