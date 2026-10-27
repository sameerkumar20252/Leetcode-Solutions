class Solution {
public:
    void dfs(vector<string>& ans, int i, int j, int m, int n) {
        ans[i][j] = '.';
        if(i == m - 1 && j == n - 1) {
            return;
        }
    
        //right
        if(j < n - 1)
        dfs(ans, i, j+1, m, n);
        //down
        else
        dfs(ans, i+1, j, m, n);
    }
    
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));

        dfs(ans, 0, 0, m, n);

        return ans;
    }
};