class Solution {
public: 
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        queue<int> Q;
        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0) {
            int size = Q.size();

            for(int i = 0; i < size; i++) {
                int u = Q.front();
                Q.pop();

                for(int v : rooms[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        Q.push(v);
                    }
                }
            }
        }

        for(bool x : vis) {
            if(x == false) return false;
        }

        return true;
    }
};