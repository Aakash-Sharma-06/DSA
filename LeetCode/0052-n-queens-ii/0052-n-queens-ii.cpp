class Solution {
public:

    bool isSafe(vector<string>& board,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q') return false;
        }

        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }

        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }

        for(int i=row,j=col ;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q') return false;
        }

        return true;
    }

    void isQueen(vector<string>& board,vector<vector<string>>& ans,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                isQueen(board,ans,row+1,n);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));

        vector<vector<string>> ans;
        isQueen(board,ans,0,n);

        return ans.size();
    }
};