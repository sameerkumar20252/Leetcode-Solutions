class Solution {
public:
    vector<int> par, rank;
    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
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


    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph[0].size();
        int prov = 0;

        par.resize(n);
        rank.resize(n);

        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(graph[i][j]) {
                    unite(i, j);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(par[i] == i) {
                prov++;
            }
        }

        return prov;
    }
};