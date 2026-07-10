class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        //{distance, node(i,j)}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {0, 0}});

        while(pq.size() > 0) {
            auto [d, node] = pq.top();
            int r = node.first;
            int c = node.second;
            pq.pop();

            if(d > dist[r][c]) {
                continue;
            }

            //up
            if(r > 0) {
                int wt = 1;
                if(d < moveTime[r-1][c]) {
                    wt += (moveTime[r-1][c] - d);
                }
                //edge relaxtation
                if(dist[r-1][c] > dist[r][c] + wt) {
                    dist[r-1][c] = dist[r][c] + wt;
                    pq.push({dist[r-1][c], {r-1, c}});
                }
            }

            //down
            if(r < m-1) {
                int wt = 1;
                if(d < moveTime[r+1][c]) {
                    wt += (moveTime[r+1][c] - d);
                }
                //edge relaxtation
                if(dist[r+1][c] > dist[r][c] + wt) {
                    dist[r+1][c] = dist[r][c] + wt;
                    pq.push({dist[r+1][c], {r+1, c}});
                }
            }

            //left
            if(c > 0) {
                int wt = 1;
                if(d < moveTime[r][c-1]) {
                    wt += (moveTime[r][c-1] - d);
                }
                //edge relaxtation
                if(dist[r][c-1] > dist[r][c] + wt) {
                    dist[r][c-1] = dist[r][c] + wt;
                    pq.push({dist[r][c-1], {r, c-1}});
                }
            }

            //right
            if(c < n-1) {
                int wt = 1;
                if(d < moveTime[r][c+1]) {
                    wt += (moveTime[r][c+1] - d);
                }
                //edge relaxtation
                if(dist[r][c+1] > dist[r][c] + wt) {
                    dist[r][c+1] = dist[r][c] + wt;
                    pq.push({dist[r][c+1], {r, c+1}});
                }
            }
        }

        return dist[m-1][n-1];
    }
};