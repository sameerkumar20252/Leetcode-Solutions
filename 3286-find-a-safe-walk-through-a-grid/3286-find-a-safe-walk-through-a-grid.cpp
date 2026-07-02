class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, tuple<int,int,int>>, vector<pair<int, tuple<int,int,int>>>, greater<pair<int, tuple<int,int,int>>>> pq;

        if(grid[0][0] == 0) {
            pq.push({0, {health, 0, 0}});
            dis[0][0] = 0;
        }
        else {
            pq.push({1, {health-1, 0, 0}});
            dis[0][0] = 1;
        }

        while(pq.size() > 0) {
            auto [d, node] = pq.top();
            pq.pop();
            auto [remHealth, i, j] = node;

            if(d > dis[i][j]) continue;
            if(remHealth < 1) continue;

            //up
            if(i > 0) {
                int wt = 0;
                int h = remHealth;
                if(grid[i-1][j] == 1) {
                    wt = 1;
                    h--;
                }
                if(dis[i-1][j] > dis[i][j] + wt && h > 0) {
                    dis[i-1][j] = dis[i][j] + wt;
                    pq.push({dis[i-1][j], {h, i-1, j}});
                }
            }
            //down
            if(i < m-1) {
                int wt = 0;
                int h = remHealth;
                if(grid[i+1][j] == 1) {
                    wt = 1;
                    h--;
                }
                if(dis[i+1][j] > dis[i][j] + wt && h > 0) {
                    dis[i+1][j] = dis[i][j] + wt;
                    pq.push({dis[i+1][j], {h, i+1, j}});
                }
            }

            //left
            if(j > 0) {
                int wt = 0;
                int h = remHealth;
                if(grid[i][j-1] == 1) {
                    wt = 1;
                    h--;
                }
                if(dis[i][j-1] > dis[i][j] + wt && h > 0) {
                    dis[i][j-1] = dis[i][j] + wt;
                    pq.push({dis[i][j-1], {h, i, j-1}});
                }
            }

            //right
            if(j < n - 1) {
                int wt = 0;
                int h = remHealth;
                if(grid[i][j+1] == 1) {
                    wt = 1;
                    h--;
                }
                if(dis[i][j+1] > dis[i][j] + wt && h > 0) {
                    dis[i][j+1] = dis[i][j] + wt;
                    pq.push({dis[i][j+1], {h, i, j+1}});
                }
            }
        }

        return dis[m-1][n-1] != INT_MAX;
    }
};