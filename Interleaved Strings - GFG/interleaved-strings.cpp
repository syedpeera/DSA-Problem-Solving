//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    bool isInterleave(string a, string b, string c) 
    {
        int m = a.size();
        int n = b.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        if(m+n != c.size()){
            return false;
        }
        
        dp[0][0] = true;
        
        for(int i=1;i<=m;i++){
            if(a[i-1]==c[i-1]){
                dp[i][0] = dp[i-1][0];
            }
        }
        for(int j=1;j<=n;j++){
            if(b[j-1]==c[j-1]){
                dp[0][j] = dp[0][j-1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==c[i+j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                if(b[j-1]==c[i+j-1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends