class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='0'){
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 1;    
                    }
                }
                else{
                    if(matrix[i][j]=='1'){
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                    }
                }
                maxArea = max(maxArea, dp[i][j]);
            }
        }
        return maxArea*maxArea;
    }
};