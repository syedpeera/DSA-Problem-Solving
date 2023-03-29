//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
        stack<long long> bucket;
        vector<long long> ans;
        for(int i=n-1;i>=0;i--){
            if(bucket.empty()){
                ans.push_back(-1);
            }
            else if(bucket.top()>nums[i]){
                ans.push_back(bucket.top());
            }
            else{
                while(!bucket.empty() && bucket.top()<=nums[i]){
                    bucket.pop();
                }
                if(bucket.empty()){
                    ans.push_back(-1);
                }
                else{
                    ans.push_back(bucket.top());
                }
            }
            bucket.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends