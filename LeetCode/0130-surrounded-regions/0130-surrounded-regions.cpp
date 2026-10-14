class Solution {
public:
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return;
        }
        
        if(vis[i][j]==true || board[i][j]=='X'){
            return;
        }
        vis[i][j]=true;

        for(auto& dir:directions){
            int i_= i+dir[0];
            int j_= j+dir[1];

            dfs(board,vis,i_,j_,m,n);
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
             if(board[i][0] == 'O')
            dfs(board,vis,i,0,m,n);

            if(board[i][n-1] == 'O')
            dfs(board,vis,i,n-1,m,n);
        }

       for(int j = 0; j < n; j++) {
        if(board[0][j] == 'O')
            dfs(board, vis, 0, j, m, n);

        if(board[m-1][j] == 'O')
            dfs(board, vis, m-1, j, m, n);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
        }
};