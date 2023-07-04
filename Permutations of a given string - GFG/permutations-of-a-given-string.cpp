//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void permutation(string &s, vector<string> &result, int l, int r){
	    if(l==r){
	        result.push_back(s);
	    }
	    else{
	        for(int i=l;i<=r;i++){
	            bool shouldSwap = true;
	            for(int j=l;j<i;j++){
	                if(s[j]==s[i]){
	                    shouldSwap = false;
	                    break;
	                }
	            }
	            if(shouldSwap){
	                swap(s[l], s[i]);
    	            permutation(s, result, l+1, r);
    	            swap(s[l], s[i]);
	            }
	        }
	    }
	}
	vector<string> find_permutation(string s)
	{
	    vector<string> result;
        permutation(s, result, 0, s.size()-1);
        return result;
	}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends