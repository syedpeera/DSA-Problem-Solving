//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void permutation(string &s, vector<string> &result, int left, int right){
	    if(left==right){
	        result.push_back(s);
	    }
	    else{
	        for(int i=left;i<=right;i++){
	            bool shouldSwap = true;
	            for(int j=left;j<i;j++){
	                if(s[j]==s[i]){
	                    shouldSwap = false;
	                    break;
	                }
	            }
	            if(shouldSwap){
	                swap(s[left], s[i]);
    	            permutation(s, result, left+1, right);
    	            swap(s[left], s[i]);
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