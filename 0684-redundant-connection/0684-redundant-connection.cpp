class Solution {
public:
    vector<int> par, rank;
    int m = -1, n = -1;
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) {
            m = a, n = b;
            return;
        }

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] < rank[parB]){
            par[parA] = parB;
        }
        else {
            par[parB] = parA;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();

        par.resize(V);
        rank.resize(V);

        for(int i = 0; i < V; i++) {
            par[i] = i;
            rank[i] = 0;
        }

        for(auto& e : edges) {
            unite(e[0]-1,e[1]-1);
            if(m != -1) {
                return {m+1,n+1};
            }
        }

        return {-1, -1};
    }
};