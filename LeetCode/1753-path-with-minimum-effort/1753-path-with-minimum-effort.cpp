class Solution {
public:

    void helper(vector<vector<int>>& heights,vector<vector<pair<int,int>>>& adj,int i,int j,int m,int n){

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int d=0; d<4; d++){
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni>=0 && ni<m && nj>=0 && nj<n){
                int wt = abs(heights[i][j] - heights[ni][nj]);
                adj[i*n+j].push_back({ni*n+nj, wt});
        }
        }

    }

    void dij(vector<vector<int>>& heights,vector<vector<pair<int,int>>>& adj,vector<int>& dis,int i,int j,int m,int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto val=pq.top();
            int e = val.first;
            int u = val.second;

            pq.pop();
            if(e > dis[u]) continue;

            for(auto v: adj[u]){
                int node = v.first;
                int wt = v.second;

                int newEffort = max(e, wt);

                if(newEffort < dis[node]){
                    dis[node]= newEffort;
                    pq.push({newEffort, node});
                }
            }
        }

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<pair<int,int>>> adj(m*n);

        //making graph with hint 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    helper(heights,adj,i,j,m,n);
            }
        }

        vector<int> dis(m*n,INT_MAX); 
 
        

        dij(heights,adj,dis,0,0,m,n);


        return dis[m*n-1];
    }
};