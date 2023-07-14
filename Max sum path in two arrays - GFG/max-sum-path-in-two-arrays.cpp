//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    int max_path_sum(int A[], int B[], int n1, int n2)
    {
        int sum1 = 0;
        int sum2 = 0;
        int i = 0, j = 0;
        int result = 0;
        while(i < n1 && j < n2){
            if(A[i] < B[j]){
                sum1 = sum1 + A[i];
                i++;
            }
            else if(A[i] > B[j]){
                sum2 = sum2 + B[j];
                j++;
            }
            else{
                result = result + A[i] + max(sum1, sum2);
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < n1){
            sum1 = sum1 + A[i];
            i++;
        }
        while(j < n2){
            sum2 = sum2 + B[j];
            j++;
        }
        result = result + max(sum1, sum2);
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}


// } Driver Code Ends