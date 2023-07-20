//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
        deque<int> dq;
        vector<int> result;

        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
        }
        result.push_back(dq.front());
        for(int i=k; i<n; i++){
            
            if(dq.front() == nums[i-k]){
                dq.pop_front();
            }
            
            while(!dq.empty() && dq.back() < nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(nums[i]);
            
            result.push_back(dq.front());
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends