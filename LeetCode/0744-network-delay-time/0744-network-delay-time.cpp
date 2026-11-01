class Solution {
public:
    void dij(int src, vector<vector<pair<int, int>>>& adj,vector<int>& dist,int n) {
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto e : adj[u]) {
                int v = e.first;
                if (dist[v] > dist[u] + e.second) {
                        dist[v] = dist[u] + e.second;
                        pq.push({dist[v],v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v, wt});
        }

        int time = 0;

        dij(k, adj,dist,n);
        
        for (int i = 1; i <=n; i++) {
            if(dist[i] == INT_MAX) return -1;
            time = max(dist[i],time);
        }
        
        return time;
    }
};