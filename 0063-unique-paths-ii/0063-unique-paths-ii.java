class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int prev[] = new int[n];
        int curr[] = new int[n];
        
        prev[0] = (obstacleGrid[0][0] == 1)? 0: 1;
        
        for(int j=1; j<n; j++){
            if(obstacleGrid[0][j] == 1){
                prev[j] = 0;
            }
            else{
                prev[j] = prev[j-1];
            }
        }
        
        for(int i=1; i<m; i++){
            curr[0] = (obstacleGrid[i][0] == 1)? 0 : prev[0];
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                }
                else{
                    curr[j] = prev[j] + curr[j-1];
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
}