//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long long firstOccurrence(vector<long long>& nums, long long target){
        long long left=0;
        long long right=nums.size()-1;
        long long index=-1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(nums[mid]==target){
                index=mid;
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return index;
    }
    long long lastOccurrence(vector<long long>& nums, long long target){
        long long left=0;
        long long right=nums.size()-1;
        long long index=-1;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(nums[mid]==target){
                index=mid;
                left=mid+1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return index;
    }  
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        return {firstOccurrence(v, x), lastOccurrence(v, x)};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends