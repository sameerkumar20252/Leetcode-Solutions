class Solution {
public:
    vector<int> par, rank;
    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) {
            par[parB] = parA;
        }
        else {
            par[parA] = parB;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        int ans = 0;
        if(edges < n - 1) {
            return -1;
        }
        par.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }

        for(auto& con : connections) {
            unionByRank(con[0], con[1]);
        }

        for(int i = 0; i < n; i++) {
            if(par[i] == i) ans++;
        }

        return ans - 1;
    }
};