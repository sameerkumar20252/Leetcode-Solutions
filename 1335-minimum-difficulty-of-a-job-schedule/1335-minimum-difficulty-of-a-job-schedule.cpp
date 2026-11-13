class Solution {
public:
    int dp[301][11];
    int fun(vector<int>& jobDifficulty, int d, int idx) {
        if(d == 1) {
            int mx = *max_element(jobDifficulty.begin() + idx, jobDifficulty.end());
            return mx;
        }
        if(dp[idx][d] != -1) {
            return dp[idx][d];
        }

        int mxdiff = INT_MIN;
        int n = jobDifficulty.size();
        int ans = INT_MAX;
        for(int i = idx; i < n - d + 1; i++) {
            mxdiff = max(mxdiff, jobDifficulty[i]);
            int temp = mxdiff + fun(jobDifficulty, d - 1, i + 1);
            ans = min(ans,temp);
        }

        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return fun(jobDifficulty, d, 0);
    }
};