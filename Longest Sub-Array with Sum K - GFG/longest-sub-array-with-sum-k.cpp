//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        int sum=0;
        int start=0;
        int end=-1;
        unordered_map<int, int> m;
        int maxLen=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            if(sum==k){
                start=0;
                end=i;
                maxLen = max(maxLen, end-start+1);
            }
            if(m.find(sum-k)!=m.end()){
                start=m[sum-k]+1;
                end=i;
                maxLen = max(maxLen,end-start+1);    
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