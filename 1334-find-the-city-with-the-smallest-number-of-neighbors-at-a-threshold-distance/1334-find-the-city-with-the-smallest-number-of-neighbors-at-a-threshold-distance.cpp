class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //floyd warshall
        vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));

        for(auto& e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            dist[u][v] = dist[v][u] = wt;
        }

        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }

        int ans = INT_MAX;
        int reachable = INT_MAX;

        for(int i = 0; i < n; i++) {
            int temp = n;
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] > distanceThreshold) {
                    temp--;
                }
            }
            if(reachable >= temp) {
                ans = i;
                reachable = temp;
            }
        }
        return ans;
    }
};