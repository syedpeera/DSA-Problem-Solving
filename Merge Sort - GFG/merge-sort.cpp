//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int left, int mid, int right)
    {
        int merged[right-left+1];
        int index1 = left;
        int index2 = mid+1;
        int x = 0;
        
        while(index1 <= mid && index2 <= right){
            if(arr[index1] <= arr[index2]){
                merged[x++] = arr[index1++];
            }
            else{
                merged[x++] = arr[index2++];
            }
        }
        
        while(index1 <= mid){
            merged[x++] = arr[index1++];
        }
        
        while(index2 <= right){
            merged[x++] = arr[index2++];
        }
        int len = sizeof(merged)/sizeof(merged[0]);
        for(int i=0,j=left;i<len;i++,j++){
            arr[j] = merged[i];
        }
    }
    public:
    void mergeSort(int arr[], int left, int right)
    {
        if(left >= right){
            return;
        }
        
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends