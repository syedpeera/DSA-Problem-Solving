//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        int n = s.size();
        int start = 0;
        reverse(s.begin(), s.end());
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                reverse(s.begin()+start, s.begin()+i);
                start=i+1;
            }
        }
        reverse(s.begin()+start, s.end());
        return s;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends