//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solveLongestRepeatingSubsequence(string s1, string s2, int n, int m){
	        vector<int> prev(m+1, 0);
	        vector<int> curr(m+1, 0);
	        for(int i=1;i<n+1;i++){
	            for(int j=1;j<m+1;j++){
	                if(s1[i-1]==s2[j-1] && i!=j){
	                    curr[j]=1+prev[j-1];
	                }
	                else{
	                    curr[j]=max(curr[j-1], prev[j]);
	                }
	            }
	            prev=curr;
	        }
	        return prev[m];
	    }
		int LongestRepeatingSubsequence(string s){
		    int n=s.size();
		    int m=n;
		    return solveLongestRepeatingSubsequence(s, s, n, m);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends