class Solution {
public: 
    void dfs(vector<vector<int>>& rooms, int u, vector<bool>& vis) {
        vis[u] = true;

        for(int v : rooms[u]) {
            if(!vis[v]) {
                dfs(rooms, v, vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);

        dfs(rooms, 0, vis);

        for(bool x : vis) {
            if(x == false) return false;
        }

        return true;
    }
};