//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int LCS(string x, string y, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
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
    int shortestCommonSupersequence(string x, string y, int n, int m)
    {
        return (n+m)-LCS(x, y, n, m);
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