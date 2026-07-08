class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector<bool>& vis) {
        for(int v : rooms[src]) {
            if(!vis[v]) {
                vis[v] = true;
                dfs(v, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlock(n, false);
        unlock[0] = true;

        dfs(0, rooms, unlock);

        for(int i = 0; i < n; i++) {
            if(!unlock[i]) {
                return false;
            }
        }

        return true;
    }
};