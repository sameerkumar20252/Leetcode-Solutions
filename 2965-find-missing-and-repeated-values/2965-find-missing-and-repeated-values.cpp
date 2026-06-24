class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int a=0,b=0;
        int n=grid.size();
        int expsum=0,actsum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actsum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);
                }
                    s.insert(grid[i][j]);
                
            }
        }
        expsum=((n*n)*((n*n)+1))/2;
        b=expsum+a-actsum;
        ans.push_back(b);
        return ans;
    }
};