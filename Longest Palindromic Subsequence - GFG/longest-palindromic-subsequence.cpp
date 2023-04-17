//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int LCS(string s1, string s2, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
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