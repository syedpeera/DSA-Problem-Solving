class Solution {
    private boolean inbound(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    
    private boolean isValid(List<String> board, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (board.get(i).charAt(col) == 'Q' || board.get(row).charAt(i) == 'Q') {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (inbound(row - i, col - i, n) && board.get(row - i).charAt(col - i) == 'Q') {
                return false;
            }
            if (inbound(row + i, col + i, n) && board.get(row + i).charAt(col + i) == 'Q') {
                return false;
            }
            if (inbound(row + i, col - i, n) && board.get(row + i).charAt(col - i) == 'Q') {
                return false;
            }
            if (inbound(row - i, col + i, n) && board.get(row - i).charAt(col + i) == 'Q') {
                return false;
            }
        }
        return true;
    }
    
    private void solveNQueensUtil(List<List<String>> result, List<String> board, int row, int n) {
        if (row == n) {
            result.add(new ArrayList<>(board));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                StringBuilder sb = new StringBuilder(board.get(row));
                sb.setCharAt(col, 'Q');
                board.set(row, sb.toString());
                solveNQueensUtil(result, board, row + 1, n);
                sb.setCharAt(col, '.');
                board.set(row, sb.toString());
            }
        }
    }
    
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        List<String> board = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; j++) {
                sb.append('.');
            }
            board.add(sb.toString());
        }

        solveNQueensUtil(result, board, 0, n);

        return result;
    }
}