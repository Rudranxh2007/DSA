class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      return  Solve(board);   
    }
    bool Solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]!='.' && !isValid(board,i,j,board[i][j])){
                    return false;
                }
            }
         }
        return true;
    }

    bool isValid(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==c) return false;
            if(i!= row &&board[i][col]==c) return false;
              int r = 3 * (row / 3) + i / 3;
            int c1 = 3 * (col / 3) + i % 3;
            if((r!=row || c1!=col)  && board[r][c1]==c) return false;
        }
        return true;
    }
};