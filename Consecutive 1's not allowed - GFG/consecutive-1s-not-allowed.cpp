//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    ll zeroEnd=1;
	    ll oneEnd=1;
	    ll sum = zeroEnd+oneEnd;
	    if(n==1){
	        return sum;
	    }
	    ll i=2;
	    while(i<=n){
	        oneEnd=zeroEnd%1000000007;
	        zeroEnd=sum%1000000007;
	        sum=(oneEnd+zeroEnd)%1000000007;
	        i++;
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends