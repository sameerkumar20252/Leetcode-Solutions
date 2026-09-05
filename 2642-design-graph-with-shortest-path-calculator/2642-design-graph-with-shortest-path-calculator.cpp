class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        this->V = n;
        adj.resize(n);
        for(auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1], e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(V, INT_MAX);
        dis[node1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});

        while(pq.size() > 0) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dis[u]) continue;

            for(auto[v, wt] : adj[u]) {
                if(dis[v] > wt + dis[u]) {
                    dis[v] = wt + dis[u];
                    pq.push({dis[v], v});
                }
            }
        }

        if(dis[node2] == INT_MAX) return -1;
        
        return dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */