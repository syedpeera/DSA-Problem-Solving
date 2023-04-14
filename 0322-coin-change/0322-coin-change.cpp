class Solution {
public:
    int solveCoinChange(vector<vector<int>>& dp, vector<int>& coins, int n, int sum){
        if(n==0){
            return  INT_MAX-1;
        }
        if(sum==0){
            return  0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(coins[n-1]<=sum){
            dp[n][sum] = min(1+solveCoinChange(dp, coins, n, sum-coins[n-1]), solveCoinChange(dp, coins, n-1, sum));
            return dp[n][sum];
        }
        else{
            dp[n][sum] = solveCoinChange(dp, coins, n-1, sum);
            return dp[n][sum];
        }
    }
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        int value = solveCoinChange(dp, coins, n, sum);
        if(value>=INT_MAX-1){
            return -1;
        }
        else{
            return value;
        }
    }
};