//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        int sum=0;
        unordered_map<int, int> m;
        int maxLen=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==k){
                maxLen = max(maxLen, i+1);
            }
            if(m.find(sum-k)!=m.end()){
                maxLen = max(maxLen,i-m[sum-k]);    
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;    
            }
        }
        return maxLen;
    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends