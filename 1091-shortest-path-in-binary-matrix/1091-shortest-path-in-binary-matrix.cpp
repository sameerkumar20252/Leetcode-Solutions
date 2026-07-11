class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        using T = tuple<int,int,int>;

        queue<T> pq;
        pq.push({1,0,0});

        while(pq.size() > 0) {
            auto [d,i,j] = pq.front();
            pq.pop();

            if(i == n-1 && j == n-1) {
                return dist[i][j];
            }

            if(d > dist[i][j]) {
                continue;
            }

            //up
            if(i > 0) {
                if(dist[i-1][j] > dist[i][j] + 1 && grid[i-1][j] != 1) {
                    dist[i-1][j] = dist[i][j] + 1;
                    pq.push({dist[i-1][j],i-1,j});
                }
                if(j > 0) {
                    if(dist[i-1][j-1] > dist[i][j] + 1 && grid[i-1][j-1] != 1) {
                        dist[i-1][j-1] = dist[i][j] + 1;
                        pq.push({dist[i-1][j-1],i-1,j-1}); 
                    }
                }
                if(j < n - 1) {
                    if(dist[i-1][j+1] > dist[i][j] + 1 && grid[i-1][j+1] != 1) {
                        dist[i-1][j+1] = dist[i][j] + 1;
                        pq.push({dist[i-1][j+1],i-1,j+1});
                    }
                }
            }

            //down
            if(i < n-1) {
                if(dist[i+1][j] > dist[i][j] + 1 && grid[i+1][j] != 1) {
                    dist[i+1][j] = dist[i][j] + 1;
                    pq.push({dist[i+1][j],i+1,j});
                }
                if(j > 0) {
                    if(dist[i+1][j-1] > dist[i][j] + 1 && grid[i+1][j-1] != 1) {
                        dist[i+1][j-1] = dist[i][j] + 1;
                        pq.push({dist[i+1][j-1],i+1,j-1}); 
                    }
                }
                if(j < n - 1) {
                    if(dist[i+1][j+1] > dist[i][j] + 1 && grid[i+1][j+1] != 1) {
                        dist[i+1][j+1] = dist[i][j] + 1;
                        pq.push({dist[i+1][j+1],i+1,j+1});
                    }
                }
            }

            //left
            if(j > 0) {
                if(dist[i][j-1] > dist[i][j] + 1 && grid[i][j-1] != 1) {
                    dist[i][j-1] = dist[i][j] + 1;
                    pq.push({dist[i][j-1],i,j-1});
                }
            }

            //right
            if(j < n - 1) {
                if(dist[i][j+1] > dist[i][j] + 1 && grid[i][j+1] != 1) {
                    dist[i][j+1] = dist[i][j] + 1;
                    pq.push({dist[i][j+1],i,j+1});
                }
            }
        }

        return -1;
    }
};