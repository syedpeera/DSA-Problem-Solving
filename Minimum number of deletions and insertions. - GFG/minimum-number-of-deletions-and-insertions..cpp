//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
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