class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
         vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges) adj[e[0]].push_back({e[1],e[2]});

        vector<vector<int>> d(n, vector<int>(k+1, 1e9));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        d[0][1] = 0;
        pq.push({0,0,1});

        while(!pq.empty()) {
            auto [w,u,c] = pq.top();
            pq.pop();

            if(w != d[u][c]) continue;
            if(u == n-1) return w;

            for(auto [v,x] : adj[u]) {
                int t = labels[u] == labels[v] ? c+1 : 1;
                if(t <= k && w+x < d[v][t]) {
                    d[v][t] = w+x;
                    pq.push({w+x,v,t});
                }
            }
        }
        return -1;
    }
};