//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string str)
{     
    int n = str.size();
    if(n == 0){
        return "";
    }
    
    string result;
    int count = 1;
    for(int i=1; i<=n; i++){
        if(i == n || str[i] != str[i-1]){
            result += str[i-1] + to_string(count);
            count = 1;
        }
        else{
            count++;
        }
    }
    return result;
}     
 
