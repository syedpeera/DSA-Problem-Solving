class Solution {
    public int solveLongestCommonSubsequence(int[][] dp, String text1, String text2, int n, int m) {
        if (n == 0 || m == 0) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (text1.charAt(n - 1) == text2.charAt(m - 1)) {
            dp[n][m] = 1 + solveLongestCommonSubsequence(dp, text1, text2, n - 1, m - 1);
            return dp[n][m];
        } else {
            dp[n][m] = Math.max(solveLongestCommonSubsequence(dp, text1, text2, n, m - 1),
                                solveLongestCommonSubsequence(dp, text1, text2, n - 1, m));
            return dp[n][m];
        }
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solveLongestCommonSubsequence(dp, text1, text2, n, m);
    }
}