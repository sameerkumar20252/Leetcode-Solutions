class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        using T = pair<int,tuple<int,int,int>>;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({0, {0,0,2}});
        const vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(pq.size() > 0) {
            auto[t, cor] = pq.top();
            pq.pop();
            int r = get<0>(cor);
            int c = get<1>(cor);
            int wt = get<2>(cor);

            if(t > dis[r][c]) continue;
            if(r == m-1 && c == n-1) break;

            for(auto[x, y] : dir) {
                x = x + r;
                y = y + c;

                if(x < 0 || y < 0 || x >= m || y >= n) continue;
                int currWt = wt == 1 ? 2 : 1;
                if(dis[x][y] > dis[r][c] + currWt) {
                    int rem = moveTime[x][y] > t ? moveTime[x][y] - t : 0;
                    dis[x][y] = rem + currWt + dis[r][c];
                    pq.push({dis[x][y], {x, y, currWt}});
                }
            }
        }

        return dis[m-1][n-1];
    }
};