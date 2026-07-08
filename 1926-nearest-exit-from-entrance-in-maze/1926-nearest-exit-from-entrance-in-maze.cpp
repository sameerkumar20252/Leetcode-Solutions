class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>> Q;
        Q.push({ent[0], ent[1]});
        int step = 0;
        maze[ent[0]][ent[1]] = '+';

        while(Q.size() > 0) {
            int size = Q.size();

            while(size--) {
                auto [r, c] = Q.front();
                Q.pop();

                if(r != ent[0] || c != ent[1]) {
                    if(r == 0 || c == 0 || r == m-1 || c == n-1) {
                        return step;
                    }
                }

                //up
                if(r > 0 && maze[r-1][c] != '+') {
                    maze[r-1][c] = '+';
                    Q.push({r - 1, c});
                }

                //dowm
                if(r < m - 1 && maze[r+1][c] != '+') {
                    maze[r+1][c] = '+';
                    Q.push({r + 1, c});
                }

                //left
                if(c > 0 && maze[r][c-1] != '+') {
                    maze[r][c-1] = '+';
                    Q.push({r, c - 1});
                }

                //right
                if(c < n - 1 && maze[r][c+1] != '+') {
                    maze[r][c+1] = '+';
                    Q.push({r, c + 1});
                }
            }
            step++;
        }

        return -1;
    }
};