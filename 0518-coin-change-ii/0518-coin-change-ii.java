class Solution {
    public int change(int amount, int[] coins) {
        int n = coins.length;
        int prev[] = new int[amount+1];
        int curr[] = new int[amount+1];
        curr[0] = 1;
        prev[0] = 1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1] <= j){
                    curr[j] = curr[j-coins[i-1]] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[amount];
    }
}