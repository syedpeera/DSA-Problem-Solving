//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int LCS(vector<vector<int>>& dp, string s1, string s2, int n, int m){
        if(n==0 || m==0){
            return 0;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1]){
            dp[n][m] = 1+LCS(dp, s1, s2, n-1, m-1);
            return dp[n][m];
        }
        else{
            dp[n][m] = max(LCS(dp, s1, s2, n, m-1), LCS(dp, s1, s2, n-1, m));
            return dp[n][m];
        }
    }
    string reverseString(string s){
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
    int longestPalinSubseq(string s) {
        string x = reverseString(s);
        int n=s.size();
        int m=x.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return LCS(dp, s, x, n, m);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends