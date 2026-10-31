class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> Q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int mins = 0; // This tracks our time levels

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    Q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        // Process level by level
        while(!Q.empty() && fresh > 0) {
            int size = Q.size(); // Capture the total oranges rotting at this specific minute
            mins++;             // Increment time for this entire batch

            for(int k = 0; k < size; k++) {
                auto [r, c] = Q.front();
                Q.pop();

                for(auto [i, j] : dir) {
                    int x = r + i;
                    int y = c + j;

                    if(x < 0 || y < 0 || x >= m || y >= n) continue;
                    if(grid[x][y] != 1) continue; // Only process fresh oranges

                    grid[x][y] = 2;
                    fresh--;
                    Q.push({x, y});
                }
            }
        }

        // Return mins instead of a stagnant ans variable
        return fresh == 0 ? mins : -1;
    }
};
