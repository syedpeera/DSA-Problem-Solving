//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	   unordered_map<char, int> frequencyMap;
	   int i=0;
	   int j=0;
	   int result=0;
	   int n=txt.size();
	   int k=pat.size();
	   for(int i=0;i<k;i++){
	       frequencyMap[pat[i]]++;
	   }
	   int count=frequencyMap.size();
	   while(j<n){
	       if(frequencyMap.find(txt[j])!=frequencyMap.end()){
	           frequencyMap[txt[j]]--;
	           if(frequencyMap[txt[j]]==0){
	               count--;
	           }
	       }
	       if(j-i+1<k){
	           j++;
	       }
	       else if(j-i+1==k){
	           if(count==0){
	               result++;
	           }
	           if(frequencyMap.find(txt[i])!=frequencyMap.end()){
	                frequencyMap[txt[i]]++;
	                if(frequencyMap[txt[i]]==1){
	                    count++;
	                }
	           }
	           i++;
	           j++;
	       }
	   }
	   return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends