//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        vector<long long int> prev(sum+1, 0);
        vector<long long int> curr(sum+1, 0);
        prev[0]=1;
        curr[0]=1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(coins[i-1]<=j){
                    curr[j] = curr[j-coins[i-1]] + prev[j];
                }
                if(coins[i-1]>j){
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends