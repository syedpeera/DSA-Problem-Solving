class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<int> prev(sum+1, INT_MAX-1);
        vector<int> curr(sum+1, 0);
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(j==0){
                    curr[j]=0;
                }
                if(i==0){
                    curr[j]=INT_MAX-1;
                }
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j){
                    curr[j] = min(1+curr[j-coins[i-1]], prev[j]);
                }
                if(coins[i-1]>j){
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        if(prev[sum]>=INT_MAX-1){
            return -1;
        }
        return prev[sum];
    }
};