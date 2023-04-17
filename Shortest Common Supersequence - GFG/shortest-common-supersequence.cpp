//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int LCS(vector<vector<int>>& dp, string x, string y, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(x[n-1]==y[m-1]){
            dp[n][m] = 1+LCS(dp, x, y, n-1, m-1);
            return dp[n][m];
        }
        else{
            dp[n][m] = max(LCS(dp, x, y, n, m-1), LCS(dp, x, y, n-1, m));
            return dp[n][m];
        }
    }
    int shortestCommonSupersequence(string x, string y, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return (n+m)-LCS(dp, x, y, n, m);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends