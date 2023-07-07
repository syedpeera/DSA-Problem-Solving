class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int m = s1.length();
        int n = s2.length();
        boolean dp[][] = new boolean[m+1][n+1];
        
        if(m+n != s3.length()){
            return false;
        }
        
        dp[0][0] = true;
        
        for(int i=1;i<=m;i++){
            if(s1.charAt(i-1)==s3.charAt(i-1)){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1;j<=n;j++){
            if(s2.charAt(j-1)==s3.charAt(j-1)){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1.charAt(i-1) == s3.charAt(i+j-1)){
                    dp[i][j] = dp[i-1][j];
                }
                if(s2.charAt(j-1) == s3.charAt(i+j-1)){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
}