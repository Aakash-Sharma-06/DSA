class Solution {
public:

    void helper(vector<vector<int>>& image,int prevColor,vector<vector<bool>>& vis,int sr,int sc,int color,int m,int n){
        if(sr<0 || sr>m || sc<0 || sc>n || vis[sr][sc]){
            return;
        }

        vis[sr][sc]=true;
        image[sr][sc]=color;

        if(sr+1<m && image[sr+1][sc]==prevColor){
            helper(image,prevColor,vis,sr+1,sc,color,m,n);
        }
        if(sr-1>=0 && image[sr-1][sc]==prevColor){
            helper(image,prevColor,vis,sr-1,sc,color,m,n);
        }
        if(sc-1>=0 && image[sr][sc-1]==prevColor){
            helper(image,prevColor,vis,sr,sc-1,color,m,n);
        }
        if(sc+1<n && image[sr][sc+1]==prevColor){
            helper(image,prevColor,vis,sr,sc+1,color,m,n);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        int prevColor=image[sr][sc];

        helper(image,prevColor,vis,sr,sc,color,m,n);

        return image;
        
    }
};