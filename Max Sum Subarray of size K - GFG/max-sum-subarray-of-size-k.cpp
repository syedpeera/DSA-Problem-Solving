//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &nums , int n){
        long maxSum = 0;
        long windowSum = 0;
        for(int i=0; i<k; i++){
            windowSum += nums[i];
        }
        maxSum = windowSum;
        for(int i=k; i<n; i++){
            windowSum = windowSum + nums[i] - nums[i-k];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends