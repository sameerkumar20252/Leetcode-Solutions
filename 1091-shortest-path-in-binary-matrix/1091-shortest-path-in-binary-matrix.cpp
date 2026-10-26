class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        using T = pair<int, pair<int,int>>;
        vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
        int n = grid.size();

        queue<T> Q;
        Q.push({1, {0, 0}});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;

        while(Q.size() > 0) {
            int size = Q.size();

            for(int i = 0; i < size; i++) {
                auto[d, u] = Q.front();
                Q.pop();
                int x = u.first;
                int y = u.second;

                if(x == n-1 && y == n-1) return d;

                for(auto[a, b] : dir) {
                    int i = a + x;
                    int j = b + y;
                    if(i < 0 || j < 0 || i >= n || j >= n) continue;
                    if(grid[i][j] == 0 && !vis[i][j]) {
                        vis[i][j] = true;
                        Q.push({d + 1, {i, j}});
                    }
                }
            }
        }

        return -1;
    }
};