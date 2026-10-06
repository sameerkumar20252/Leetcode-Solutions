class Solution {
public:
    // vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    // void bfs(int r, int c, vector<vector<char>>& grid) {
    //     queue<pair<int,int>> Q;
    //     Q.push({r, c});
    //     grid[r][c] = '0';

    //     while(Q.size() > 0) {
    //         auto[i, j] = Q.front();
    //         Q.pop();

    //         for(auto[x, y] : dir) {
    //             int a = i + x;
    //             int b = j + y;
    //             if(a < 0 || b < 0 || a >= grid.size() || b >= grid[0].size()) continue;
    //             if(grid[a][b] == '1') {
    //                 grid[a][b] = '0';
    //                 Q.push({a,b});
    //             }
    //         }
    //     }
    // }

    void dfs(int r, int c, vector<vector<char>>& grid) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()
            || grid[r][c] == '0') return;
        grid[r][c] = '0';

        dfs(r - 1, c, grid);
        dfs(r + 1, c, grid);
        dfs(r, c - 1, grid);
        dfs(r, c + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};