//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int nums[], int n, int target)
    {
        sort(nums, nums+n);
        int j = 0, k = 0;
        int closestSum = INT_MAX;
        for(int i=0; i<n; i++){
            j = i + 1;
            k = n - 1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(closestSum - target)){
                    closestSum = sum;
                }
                
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        return closestSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends