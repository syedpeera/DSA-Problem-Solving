class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && dfs(board, i, j, 0, word)){
                    return true; 
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, int count, string& word){
        if(count==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[count]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        bool found = dfs(board, i-1, j, count+1, word) ||
                    dfs(board, i, j-1, count+1, word) ||
                    dfs(board, i+1, j, count+1, word) ||
                    dfs(board, i, j+1, count+1, word);
        board[i][j]=temp;
        return found;
    }
};