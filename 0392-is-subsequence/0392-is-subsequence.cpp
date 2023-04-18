class Solution {
public:
    int LCS(string s1, string s2, int n, int m){
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(curr[j-1], prev[j]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }
    bool isSubsequence(string s1, string s2) {
        if(LCS(s1,s2, s1.size(), s2.size())==s1.size()){
            return true;    
        }
        else{
            return false;
        }        
    }
};