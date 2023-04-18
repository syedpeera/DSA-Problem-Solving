//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string s1, string s2) 
    {
        int n=s1.size();
        int m=s2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s1[i]==s2[j]){
                i++;
            }
            j++;
        }
        if(i==n){
            return true;
        }
        else{
            return false;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends