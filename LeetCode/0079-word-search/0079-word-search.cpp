class Solution {
public:

    bool isFind(vector<vector<char>>& board, string& word,int row, int col, int idx){
        if(idx==word.length()){
            return true;
        }

        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size() ||
           board[row][col] != word[idx]) {
            return false;
        }

        board[row][col]='#';

        bool Found= isFind(board,word,row+1,col,idx+1)||
                    isFind(board,word,row,col+1,idx+1) ||
                    isFind(board,word,row-1,col,idx+1) ||
                    isFind(board,word,row,col-1,idx+1);

        board[row][col]=word[idx];

        return Found;

    }

    bool exist(vector<vector<char>>& board, string word) {

         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                if(isFind(board,word,i,j,0))
                    return true;
            }
        }

        return false;
    }
};