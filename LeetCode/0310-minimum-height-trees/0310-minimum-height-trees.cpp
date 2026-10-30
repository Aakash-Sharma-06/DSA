class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n,0);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;  
        }

        queue<int> q;
        
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }


        int rem=n;

        while(rem > 2){

            int size=q.size();
            rem-= size;

            for(int i=0;i<size;i++){
                int u=q.front();
                q.pop();

                for(auto v:adj[u]){

                    degree[v]--;   

                    if(degree[v]==1){
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};