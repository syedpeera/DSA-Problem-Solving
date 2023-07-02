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
    int partition (int arr[], int low, int high)
    {
       int pivot = arr[high];
       int i = low-1;
       
       for(int j=low;j<high;j++){
           if(arr[j] < pivot){
               i++;
               int temp = arr[j];
               arr[j] = arr[i];
               arr[i] = temp;
           }
       }
       i++;
       int temp = arr[i];
       arr[i] = arr[high];
       arr[high] = temp;
       return i; //Pivot Index
    }
    void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int pivotIndex = partition(arr, low, high);
            quickSort(arr, low, pivotIndex-1);
            quickSort(arr, pivotIndex+1, high);
        }
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends