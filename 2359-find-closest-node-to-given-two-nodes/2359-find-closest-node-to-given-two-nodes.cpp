class Solution {
public:
    void dfs(int u, vector<int>& edges, vector<int>& dis, int time) {
        if(dis[u] != -1) return;
        dis[u] = time;

        if(edges[u] == -1) return;
        dfs(edges[u], edges, dis, time + 1);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> n1(n, -1);
        vector<int> n2(n, -1);

        dfs(node1, edges, n1, 0);
        dfs(node2, edges, n2, 0);

        int best = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            if(n1[i] != -1 && n2[i] != -1) {
                int mx = max(n1[i], n2[i]);
                if(mx < best) {
                    best = mx;
                    ans = i;
                }
            }
        }

        return ans;
    }
};