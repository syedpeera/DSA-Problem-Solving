class Solution {
public:
    bool hasWon(vector<string>& board, char player){
        for(int i=0; i<3; i++){
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
                return true;
            }
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player){
                return true;
            }
        }
        if(board[0][0] == player && board[1][1] == player && board[2][2] == player){
            return true;
        }
        if(board[0][2] == player && board[1][1] == player && board[2][0] == player){
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int countX = 0;
        int countO = 0;
        for(int i=0; i<3; i++){
            int n = board[i].size();
            for(int j=0; j<n; j++){
                if(board[i][j] == 'X'){
                    countX++;
                }
                else if(board[i][j] == 'O'){
                    countO++;
                }
            }
        }
        
        if(countX < countO || countX > countO + 1){
            return false;
        }
        
        bool xWin = hasWon(board, 'X');
        bool oWin = hasWon(board, 'O');
        
        if(xWin==true && oWin==true){
            return false;
        }
        if(xWin==true && countX == countO){
            return false;
        }
        if(oWin==true && countX > countO){
            return false;
        }
        return true;
    }
};