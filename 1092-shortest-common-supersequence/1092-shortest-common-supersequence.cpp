class Solution {
public:
    int solveLongestCommonSubsequence(vector<vector<int>>& dp, string text1, string text2, int n, int m){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    string printShortestCommonSuperSequence(vector<vector<int>>& dp, string text1, string text2){
        int i=text1.size();
        int j=text2.size();
        string result="";
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                result=result+text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                result=result+text1[i-1];
                i--;
            }
            else{
                result=result+text2[j-1];
                j--;
            }
        }
        while(i>0){
            result=result+text1[i-1];
            i--;
        }
        while(j>0){
            result=result+text2[j-1];
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int length = solveLongestCommonSubsequence(dp, s1, s2, n, m);
        return printShortestCommonSuperSequence(dp, s1,s2);   
    }
};