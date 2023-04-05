//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int search(int arr[], int n, int x,bool flag){
        int left=0;
        int right=n-1;
        int index=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]<x){
                left=mid+1;
            }
            else if(arr[mid]>x){
                right=mid-1;
            }
            else{
                index=mid;
                if(flag==true){
                    right=mid-1;
                }
                else{
                    left=mid+1;   
                }
            }
        }
        return index;
    }

	int count(int arr[], int n, int x) {
        int firstOccurrence = search(arr, n, x, true);
        int lastOccurrence = search(arr, n, x, false);
        if(firstOccurrence==-1 || lastOccurrence==-1){
            return 0;
        }
        return lastOccurrence-firstOccurrence+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends