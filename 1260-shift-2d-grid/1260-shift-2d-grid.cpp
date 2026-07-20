class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> temp(m * n);
        int a = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[a++] = grid[i][j]; 
            }
        }

        int K = k % (m * n);

        while(K--) {
            temp.insert(temp.begin(), temp.back());
            temp.pop_back();
        }
        a = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                grid[i][j] = temp[a++]; 
            }
        }

        return grid;
    }
};