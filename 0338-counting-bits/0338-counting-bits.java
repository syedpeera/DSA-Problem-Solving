class Solution {
    public int[] countBits(int n) {
        int dp[] = new int[n+1];
        for(int i=1;i<=n;i++){
            int digit = (i & 1);
            dp[i] = dp[i>>1] + digit;
        }
        return dp;
    }
}