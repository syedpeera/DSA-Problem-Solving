//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void segregateEvenOdd(int arr[], int n) {
	    int left = 0;
	    int right = n-1;
	    while(left < right){
	        while(arr[left] % 2 == 0 && left < right){
	            left++;
	        }
	        while(arr[right] % 2 != 0 && left < right){
	            right--;
	        }
	        if(left < right){
	            swap(arr[left], arr[right]);
	        }
	    }
	    sort(arr, arr+left);
	    sort(arr+left, arr+n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends