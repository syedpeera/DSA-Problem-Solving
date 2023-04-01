//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    public:
    long long trappingWater(int arr[], int n){
        int left=1;
        int right=n-2;
        int leftMax=arr[0];
        int rightMax=arr[n-1];
        long long totalWater=0;
        while(left<=right){
            if(leftMax<rightMax){
                if(arr[left]>leftMax){
                    leftMax=arr[left];
                }
                else{
                    totalWater+=leftMax-arr[left];
                }
                left++;
            }
            else{
                if(arr[right]>rightMax){
                    rightMax=arr[right];
                }
                else{
                    totalWater+=rightMax-arr[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends