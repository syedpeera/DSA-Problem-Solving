//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        int maxVal=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                    maxVal=max(maxVal, curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return maxVal;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends