class Solution {
public:

    void helper(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid,int m,int n){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j]!='1'){
            return;
        }
        vis[i][j] = true;

        helper(i+1,j,vis,grid,m,n);
        helper(i-1,j,vis,grid,m,n);
        helper(i,j+1,vis,grid,m,n);
        helper(i,j-1,vis,grid,m,n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== '1' && !vis[i][j]){
                    helper(i,j,vis,grid,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};