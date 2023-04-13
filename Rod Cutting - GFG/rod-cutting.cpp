//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solveCutRod(vector<vector<int>>& dp, int price[], vector<int>& lengths, int n, int len){
        if(n==0 || len==0){
            return 0;
        }
        if(dp[n][len]!=-1){
            return dp[n][len];
        }
        if(lengths[n-1]<=len){
            dp[n][len] = max( (price[n-1]+solveCutRod(dp, price, lengths, n, len-lengths[n-1])), solveCutRod(dp, price, lengths, n-1, len));
            return dp[n][len];
        }
        if(lengths[n-1]>len){
            dp[n][len] = solveCutRod(dp, price, lengths, n-1, len);
            return dp[n][len];
        }
    }
    int cutRod(int price[], int n) {
        vector<int> lengths;
        for(int i=0;i<n;i++){
            lengths.push_back(i+1);
        }
        int len=lengths.size();
        vector<vector<int>> dp(n+1, vector<int>(len+1, -1));
        return solveCutRod(dp, price, lengths, n, len);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends