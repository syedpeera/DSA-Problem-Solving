//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solveKnapSack(vector<vector<int>>& dp, int wt[], int val[], int w, int n){
        if(n==0 || w==0){
            return 0;
        }
        if(dp[n][w]!=-1){
            return dp[n][w];
        }
        if(wt[n-1]<=w){
            dp[n][w] = max((val[n-1]+solveKnapSack(dp, wt, val, w-wt[n-1], n-1)), solveKnapSack(dp, wt, val, w, n-1));
            return dp[n][w];
        }
        else if(wt[n-1]>w){
            dp[n][w] = solveKnapSack(dp, wt, val, w, n-1);
            return dp[n][w];
        }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        return solveKnapSack(dp, wt, val, w, n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends