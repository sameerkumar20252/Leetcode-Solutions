class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n) return true;
        if(grid[r][c] == 1) return false;

        grid[r][c] = 1;

        bool left = dfs(grid, r - 1, c);
        bool right = dfs(grid, r + 1, c);
        bool up = dfs(grid, r, c - 1);
        bool down = dfs(grid, r, c + 1);

        return left || right || up || down;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    if(!dfs(grid, i, j)) {
                        island++;
                    }
                }
            }
        }

        return island;
    }
};