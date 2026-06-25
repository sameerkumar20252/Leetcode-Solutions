class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i > 0) {
                    if(mat[i][j] <= mat[i-1][j]) {
                        continue;
                    }
                }
                if(j > 0) {
                    if(mat[i][j] <= mat[i][j-1]) {
                        continue;
                    }
                }
                if(i < m - 1) {
                    if(mat[i][j] <= mat[i+1][j]) {
                        continue;
                    }
                }
                if(j < n - 1) {
                    if(mat[i][j] <= mat[i][j+1]) {
                        continue;
                    }
                }

                return {i,j};
            }
        }

        return ans;
    }
};