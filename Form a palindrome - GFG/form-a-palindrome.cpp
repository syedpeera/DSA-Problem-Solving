//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int LCS(string s1, string s2, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(n+1, 0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j]=max(curr[j-1], prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    int LPS(string s){
        int n=s.size();
        int m=n;
        string x=s;
        reverse(x.begin(), x.end());
        return LCS(s, x, n, m);
    }
    int findMinInsertions(string s){
        int n=s.size();
        return n-LPS(s);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends