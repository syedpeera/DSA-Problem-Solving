//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        int minVal=INT_MAX;
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int len=2;len<=n-1;len++){
            for(int i=1;i<=n-len;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    int temp = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    dp[i][j]=min(temp, dp[i][j]);
                }
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends