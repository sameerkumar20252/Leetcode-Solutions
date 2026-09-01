class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        dis[0][0] = grid[0][0] == 1 ? 1 : 0;
        pq.push({dis[0][0], {0, 0}});

        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(pq.size() > 0) {
            int currDis = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(currDis > dis[r][c]) continue;

            for(auto [x, y] : dir) {
                int vr = r + x;
                int vc = c + y;

                if(vr < 0 || vc < 0 || vr >= m || vc >= n) continue;
                int wt = 0;
                if(grid[vr][vc] == 1) {
                    wt = 1;
                }

                if(dis[vr][vc] > dis[r][c] + wt) {
                    dis[vr][vc] = dis[r][c] + wt;
                    pq.push({dis[vr][vc], {vr, vc}});
                }
            }
        }

        return dis[m-1][n-1];
    }
};