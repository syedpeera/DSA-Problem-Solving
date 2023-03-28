//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long a[], long long n, long long k1, long long k2)
    {
        priority_queue<long long> maxHeap;
        long long sum=0;
        for(int i=0;i<n;i++){
            maxHeap.push(a[i]);
        }
        while(!maxHeap.empty()){
            if(maxHeap.size()>k1 && maxHeap.size()<k2){
                sum+=maxHeap.top();
            }
            
            maxHeap.pop();
        }
        return sum;
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
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends