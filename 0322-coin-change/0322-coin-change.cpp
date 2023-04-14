class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(j==0){
                    dp[i][j]=0;
                }
                if(i==0){
                    dp[i][j]=INT_MAX-1;
                }
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
                }
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][sum]>=INT_MAX-1){
            return -1;
        }
        return dp[n][sum];
    }
};