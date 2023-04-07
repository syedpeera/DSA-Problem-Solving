//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int findFloor(vector<long long> nums, long long n, long long x){
        long long left=0;
        long long right=n-1;
        long long result=INT_MAX;
        int index=-1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(nums[mid]==x){
                return mid;
            }
            else if(nums[mid]<x){
                index=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return index;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends