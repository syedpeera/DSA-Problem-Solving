//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LCS(string x, string y, int n, int m){
	    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<m+1;j++){
	            if(i==0 || j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
	            if(x[i-1]==y[j-1]){
	                dp[i][j] = 1+dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	            }
	        }
	    }
	    return dp[n][m];
	}
	int minOperations(string x, string y) 
	{ 
	    int n=x.size();
	    int m=y.size();
	    int numberOfDeletions = n - LCS(x, y, n, m);
	    int numberOfInsertions = m - LCS(x, y, n, m);
	    return numberOfDeletions + numberOfInsertions;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends