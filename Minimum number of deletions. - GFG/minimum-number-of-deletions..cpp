//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

int LCS(string s1, string s2, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
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
    return LCS(s, x, n, m);
}
int minDeletions(string str, int n) { 
    return n-longestPalinSubseq(str);    
} 