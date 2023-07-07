class Solution {
    public int solveChange(int coins[], int n, int amount, int dp[][]){
        if(amount == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1] <= amount){
            dp[n][amount] = solveChange(coins, n, amount-coins[n-1], dp) + solveChange(coins, n-1, amount, dp);
            return dp[n][amount];
        }
        else{
            dp[n][amount] = solveChange(coins, n-1, amount, dp);
            return dp[n][amount];
        }
    }
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int dp[][] = new int[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
}