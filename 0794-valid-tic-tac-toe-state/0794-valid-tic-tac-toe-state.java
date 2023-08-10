class Solution {
    public boolean hasWon(String[] board, char player){
        for(int i=0; i<3; i++){
            if(board[i].charAt(0) == player && board[i].charAt(1) == player && board[i].charAt(2) == player){
                return true;
            }
            if(board[0].charAt(i) == player && board[1].charAt(i) == player && board[2].charAt(i) == player){
                return true;
            }
        }
        if(board[0].charAt(0) == player && board[1].charAt(1) == player && board[2].charAt(2) == player){
            return true;
        }
        if(board[0].charAt(2) == player && board[1].charAt(1) == player && board[2].charAt(0) == player){
            return true;
        }
        return false;
    }
    public boolean validTicTacToe(String[] board) {
        int countX = 0;
        int countO = 0;
        for(int i=0; i<3; i++){
            int n = board.length;
            for(int j=0; j<n; j++){
                if(board[i].charAt(j) == 'X'){
                    countX++;
                }
                if(board[i].charAt(j) == 'O'){
                    countO++;
                }
            }
        }
        
        if(countX < countO || countX > countO + 1){
            return false;
        }
        
        boolean xWin = hasWon(board, 'X');
        boolean oWin = hasWon(board, 'O');
        
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
}