class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> par(n);
        par[0] = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] <= maxDiff) {
                par[i] = par[i-1];
            }
            else {
                par[i] = i;
            }
        }

        int m = queries.size();

        vector<bool> ans(m);
        for(int i = 0; i < m; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = (par[u] == par[v]);
        }

        return ans;
    }
};