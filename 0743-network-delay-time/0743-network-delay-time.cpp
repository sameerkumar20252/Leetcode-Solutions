class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Bellman-Ford
        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;

        for(int i = 0; i < n; i++) {
            for(vector<int>& time : times) {
                int u = time[0]-1;
                int v = time[1]-1;
                int wt = time[2];

                if(dis[u] != INT_MAX && dis[v] > dis[u] + wt) {
                    if(i == n-1) return -1;
                    dis[v] = dis[u] + wt;
                }
            }
        }

        int ans = INT_MIN;

        for(int x : dis) {
            if(x == INT_MAX) return -1;
            ans = max(ans, x);
        }

        return ans;
    }
};