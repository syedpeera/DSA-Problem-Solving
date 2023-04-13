//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> lengths;
        for(int i=0;i<n;i++){
            lengths.push_back(i+1);
        }
        int len=lengths.size();
        vector<int> prev(len+1, 0);
        vector<int> curr(len+1, 0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<len+1;j++){
                if(lengths[i-1]<=j){
                    curr[j] = max(price[i-1]+curr[j-lengths[i-1]], prev[j]);
                }
                if(lengths[i-1]>j){
                    curr[j] = prev[j];
                }    
            }
            prev=curr;
        }
        return prev[len];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends