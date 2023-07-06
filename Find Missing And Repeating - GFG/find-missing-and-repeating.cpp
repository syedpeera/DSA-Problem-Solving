//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int xorResult = 0;
        for(int i=0;i<n;i++){
            xorResult ^= arr[i];
            xorResult ^= (i+1);
        }
        int rightMostSetBit = xorResult & ~(xorResult-1);
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if((arr[i] & rightMostSetBit)!=0){
                x ^= arr[i];
            }
            else{
                y ^= arr[i];
            }
            if(((i+1) & rightMostSetBit)!=0){
                x ^= (i+1);
            }
            else{
                y ^= (i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                return {x, y};
            }
        }
        return {y, x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends