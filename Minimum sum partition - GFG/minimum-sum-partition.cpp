//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        bool dp[n+1][sum+1];
        //isSubset(nums, sum, dp);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0){
                    dp[i][j]=false;    
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                if(nums[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        /* s1-s2 => range - 2*s1 => sum - 2*s1 => totalsumofarray - 2*s1 */
        int minimumDifference = sum;
        for(int i = 0; i <= sum/2; i++) {
            if(dp[n][i]) {
                minimumDifference = min(minimumDifference, sum - 2*i);
            }
        }
        return minimumDifference;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends