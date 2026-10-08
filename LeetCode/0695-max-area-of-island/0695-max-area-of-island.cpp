class Solution {
public:

    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis,int m,int n,int& a){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]!=1){
            return a;
        }
        vis[i][j]= true;

        a++;
        helper(grid,i+1,j,vis,m,n,a);
        helper(grid,i-1,j,vis,m,n,a);
        helper(grid,i,j+1,vis,m,n,a);
        helper(grid,i,j-1,vis,m,n,a);

        return a;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int a=0;
                    area= max(area,helper(grid,i,j,vis,m,n,a));
                }
            }
        }
        return area;
    }
};