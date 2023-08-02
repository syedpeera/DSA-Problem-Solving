class Solution {
public:
    bool inbound(int i, int j, int n){
        if(i<0 || j<0 || i>=n || j>=n){
            return false;
        }
        return true;
    }
    bool isValid(vector<string> &board, int row, int col, int n){
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q' || board[row][i] == 'Q'){
                return false;
            }
        }
        
        for(int i=0; i<n; i++){
            if(inbound(row-i, col-i, n) && board[row-i][col-i] == 'Q'){
                return false;
            }
            if(inbound(row+i, col+i, n) && board[row+i][col+i] == 'Q'){
                return false;
            }
            if(inbound(row+i, col-i, n) && board[row+i][col-i] == 'Q'){
                return false;
            }
            if(inbound(row-i, col+i, n) && board[row-i][col+i] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solveNQueensUtil(vector<vector<string>> &result, vector<string> &board, int row, int n){
        if(row == n){
            result.push_back(board);
            return;
        }
        for(int col=0; col<n; col++){
            if(isValid(board, row, col, n)){
                board[row][col] = 'Q';
                solveNQueensUtil(result, board, row+1, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensUtil(result, board, 0, n);
        return result;
    }
};