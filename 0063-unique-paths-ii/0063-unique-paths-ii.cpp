class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        //vector<vector<int>> dp(m, vector<int>(n, 0));
        prev[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        
        // Initialize first row using prev array
        for(int j = 1; j < n; j++) {
            if(obstacleGrid[0][j] == 1) {
                prev[j] = 0;
            } else {
                prev[j] = prev[j - 1];
            }
        }
        
        // DP calculation
        for(int i = 1; i < m; i++) {
            curr[0] = obstacleGrid[i][0] == 1 ? 0 : prev[0];
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else {
                    curr[j] = prev[j] + curr[j - 1];
                }
            }
            prev = curr;
        }
        
        return prev[n - 1];
    }
};
