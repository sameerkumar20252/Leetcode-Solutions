class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n, int& path) {
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] != 1) {
            return;
        }
        path++;
        grid[r][c] = 0;

        dfs(grid, r - 1, c, m, n, path);
        dfs(grid, r + 1, c, m, n, path);
        dfs(grid, r, c - 1, m, n, path);
        dfs(grid, r, c + 1, m, n, path);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxPath = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int path = 0;
                    dfs(grid, i, j, m, n, path);
                    maxPath = max(maxPath, path);
                }
            }
        }

        return maxPath;
    }
};