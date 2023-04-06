//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
        int left=0;
        int right=n-1;
        while(left<=right){
            if(nums[left]<=nums[right]){
                return left;
            }
            int mid=left+(right-left)/2;
            int next=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return mid;
            }
            else if(nums[left]<=nums[mid] && nums[mid]>=nums[right]){
                left=mid+1;
            }
            else if(nums[left]>=nums[mid] && nums[mid]<=nums[right]){
                right=mid-1;
            }
        }
        return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends