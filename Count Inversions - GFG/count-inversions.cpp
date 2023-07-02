//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long int merge(long long arr[], long long left, long long mid, long long right)
    {
        long long merged[right-left+1];
        long long index1 = left;
        long long index2 = mid+1;
        long long x = 0;
        long long int countInversions = 0;
        
        while(index1 <= mid && index2 <= right){
            if(arr[index1] <= arr[index2]){
                merged[x++] = arr[index1++];
            }
            else{
                merged[x++] = arr[index2++];
                countInversions += (mid - index1 + 1);
            }
        }
        
        while(index1 <= mid){
            merged[x++] = arr[index1++];
        }
        
        while(index2 <= right){
            merged[x++] = arr[index2++];
        }
        long long len = sizeof(merged)/sizeof(merged[0]);
        for(long long i=0,j=left;i<len;i++,j++){
            arr[j] = merged[i];
        }
        return countInversions;
    }
    long long int mergeSort(long long arr[], long long left, long long right)
    {
        long long int countInversions = 0;
        if(left < right){
            int mid = left + (right-left)/2;
            countInversions += mergeSort(arr, left, mid);
            countInversions += mergeSort(arr, mid+1, right);
            countInversions += merge(arr, left, mid, right);    
        }
        return countInversions;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends