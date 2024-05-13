class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int score = (1 << (n - 1)) * m;

        for (int j = 1; j < n; j++) {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) {
                
                if (grid[i][j] == grid[i][0]) {
                    countSameBits++;
                }
            }
            
            countSameBits = Math.max(countSameBits, m - countSameBits);
            
            int columnScore = (1 << (n - j - 1)) * countSameBits;
            
            score += columnScore;
        }

        return score;
    }
}