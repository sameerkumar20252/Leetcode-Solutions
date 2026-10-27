class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int src = start;
        queue<pair<int,int>> Q;
        Q.push({src, 0});
        vector<int> vis(n, false);
        vis[start] = true;

        while(Q.size() > 0) {
            int size = Q.size();

            for(int i = 0; i < size; i++) {
                auto[u, d] = Q.front();
                Q.pop();
                if(nums[u] == target) {
                    if(d < 0) d = d * -1;
                    return d;
                }
                //right
                if(u < n - 1) {
                    int x = u + 1;
                    if(!vis[x]) {
                        vis[x] = true;
                        Q.push({x, d + 1});
                    }
                }
                //left
                if(u > 0) {
                    int x = u - 1;
                    if(!vis[x]) {
                        vis[x] = true;
                        Q.push({x, d - 1});
                    }
                }
            }
        }

        return 0;
    }
};