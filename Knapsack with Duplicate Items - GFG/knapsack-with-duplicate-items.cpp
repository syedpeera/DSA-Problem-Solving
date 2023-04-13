//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solveKnapSack(vector<vector<int>>& dp, int n, int w, int val[], int wt[]){
        if(n==0 || w==0){
            return 0;
        }
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        if(wt[n-1]<=w){
            dp[n][w] = max((val[n-1]+solveKnapSack(dp, n, w-wt[n-1], val, wt)), solveKnapSack(dp, n-1, w, val, wt));
            return dp[n][w];
        }
        else if(wt[n-1]>w){
            dp[n][w] = solveKnapSack(dp, n-1, w, val, wt);
            return dp[n][w];
        }
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return solveKnapSack(dp, n, w, val, wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends