class Solution {
public:
    void dfs(int i,vector<vector<int>>& Adj, vector<bool>& vis){
        vis[i]=true;

        for(int j=0; j<Adj[i].size();j++){
            if(!vis[j] && Adj[i][j]==1){
                dfs(j,Adj,vis);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;

    }
};