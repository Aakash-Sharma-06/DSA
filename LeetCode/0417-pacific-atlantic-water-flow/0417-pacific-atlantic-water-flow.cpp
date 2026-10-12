
class Solution {
public:
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& heights,int i,int j,int preVal,vector<vector<bool>>& vis){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size()){
            return;
        }

        if(heights[i][j]<preVal || vis[i][j]){
            return;
        }

        vis[i][j]=true;

        for(auto& dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];

            dfs(heights,i_,j_,heights[i][j],vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        vector<vector<int>> result;

        vector<vector<bool>> pacvis(m,vector<bool>(n,false));
        vector<vector<bool>> atvis(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            dfs(heights,0,j,INT_MIN,pacvis);
            dfs(heights,m-1,j,INT_MIN,atvis);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,0,INT_MIN,pacvis);
            dfs(heights,i,n-1,INT_MIN,atvis);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacvis[i][j] && atvis[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};
