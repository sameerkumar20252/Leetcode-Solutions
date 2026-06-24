class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        if(k >= m + n - 2) {
            return m + n - 2;
        }
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n,vector<bool>(k + 1, false)));
        queue<vector<int>> Q;
        vis[0][0][k] = true;
        Q.push({0,0,k,0}); //{i,j,rem,step}

        while(Q.size() > 0) {
            auto x = Q.front();
            Q.pop();
            int r = x[0];
            int c = x[1];
            int rem = x[2];
            int step = x[3];

            if(r == m - 1 && c == n - 1) {
                return step;
            }


            if(r > 0) {
                if(grid[r-1][c] == 0 && !vis[r-1][c][rem]) {
                    vis[r-1][c][rem] = true;
                    Q.push({r-1,c,rem,step+1});
                }
                if(grid[r-1][c] == 1 && rem > 0 && !vis[r-1][c][rem-1]) {
                    vis[r-1][c][rem-1] = true;
                    Q.push({r-1,c,rem-1,step+1});
                }
            }
             if(c > 0) {
                if(grid[r][c-1] == 0 && !vis[r][c-1][rem]) {
                    vis[r][c-1][rem] = true;
                    Q.push({r,c-1,rem,step+1});
                }
                if(grid[r][c-1] == 1 && rem > 0 && !vis[r][c-1][rem-1]) {
                    vis[r][c-1][rem-1] = true;
                    Q.push({r,c-1,rem-1,step+1});
                }
            }
             if(r < m - 1) {
                if(grid[r+1][c] == 0 && !vis[r+1][c][rem]) {
                    vis[r+1][c][rem] = true;
                    Q.push({r+1,c,rem,step+1});
                }
                if(grid[r+1][c] == 1 && rem > 0 && !vis[r+1][c][rem-1]) {
                    vis[r+1][c][rem-1] = true;
                    Q.push({r+1,c,rem-1,step+1});
                }
            }
            if(c < n - 1) {
                if(grid[r][c+1] == 0 && !vis[r][c+1][rem]) {
                    vis[r][c+1][rem] = true;
                    Q.push({r,c+1,rem,step+1});
                }
                if(grid[r][c+1] == 1 && rem > 0 && !vis[r][c+1][rem-1]) {
                    vis[r][c+1][rem-1] = true;
                    Q.push({r,c+1,rem-1,step+1});
                }
            }
        }

        return -1;
    }
};