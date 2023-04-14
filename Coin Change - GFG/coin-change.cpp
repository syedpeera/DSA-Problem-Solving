//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int solveCount(vector<vector<long long int>>& dp, int coins[], int n, int sum){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(coins[n-1]<=sum){
            dp[n][sum] = solveCount(dp, coins, n, sum-coins[n-1]) + solveCount(dp, coins, n-1, sum);   
            return dp[n][sum];
        }
        if(coins[n-1]>sum){
            dp[n][sum] = solveCount(dp, coins, n-1, sum);
            return dp[n][sum];
        }
    }
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(sum+1, -1));
        return solveCount(dp, coins, n, sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends