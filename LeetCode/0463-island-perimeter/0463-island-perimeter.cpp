class Solution {
public:

    void helper(int i,int j,vector<vector<bool>>& vis,vector<vector<int>>& grid,int m,int n,int& per){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || grid[i][j]!=1){
            return;
        }
        vis[i][j] = true;

        if( i+1>=n || grid[i+1][j]!=1) per++;
        if( i-1<0 || grid[i-1][j]!=1) per++;
        if( j+1>=m || grid[i][j+1]!=1) per++;
        if( j-1<0 || grid[i][j-1]!=1) per++;

        helper(i+1,j,vis,grid,m,n,per);
        helper(i-1,j,vis,grid,m,n,per);
        helper(i,j+1,vis,grid,m,n,per);
        helper(i,j-1,vis,grid,m,n,per);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int per=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]== 1 && !vis[i][j]){
                    helper(i,j,vis,grid,m,n,per);
                }
            }
        }
        return per;
    }
};