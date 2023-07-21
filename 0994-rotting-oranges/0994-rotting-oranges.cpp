class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //<<rowIndex, colIndex> , time>
        queue<pair<pair<int, int>, int>> q;
        int rowSize = grid.size();
        int colSize = grid[0].size();
        vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
        int countFresh = 0;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                    countFresh++;
                }
            }
        }
        int totalTime = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int count = 0;
        while(!q.empty()){
            int rowIndex = q.front().first.first;
            int colIndex = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newRowIndex = rowIndex + drow[i];
                int newColIndex = colIndex + dcol[i];
                
                if(newRowIndex >= 0 && newRowIndex < rowSize && newColIndex >= 0 && newColIndex < colSize && grid[newRowIndex][newColIndex] == 1 && visited[newRowIndex][newColIndex] == 1){
                    q.push({{newRowIndex, newColIndex}, time+1});
                    visited[newRowIndex][newColIndex] = 2;
                    count++;
                }
            }
            totalTime = time;
        }
        if(countFresh != count){
            return -1;
        }
        return totalTime;
    }
};