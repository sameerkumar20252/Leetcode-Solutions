class Solution {
public:
     void dfs(vector<vector<int>>& grid, int r, int c, int& sum) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return;

        sum += grid[r][c];
        grid[r][c] = 0;

        dfs(grid, r + 1, c, sum);
        dfs(grid, r, c + 1, sum);
        dfs(grid, r - 1, c, sum);
        dfs(grid, r, c - 1, sum);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] != 0) {
                    int sum = 0;
                    dfs(grid, i, j, sum);
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};