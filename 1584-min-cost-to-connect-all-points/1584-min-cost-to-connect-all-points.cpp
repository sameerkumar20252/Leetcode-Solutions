class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); //{wt,u}
        int minCost = 0;


        while(pq.size() > 0) {
            auto [wt, u] = pq.top();
            pq.pop();

            if(!vis[u]) {
                vis[u] = true;
                minCost += wt;

                for(int v = 0; v < n; v++) {
                    if(!vis[v]) {
                        auto& p1 = points[u];
                        auto& p2 = points[v];
                        int dis = abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);

                        pq.push({dis, v});
                    }
                }
            } 
        }   

        return minCost;
    }
};