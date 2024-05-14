class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int totalGold = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                totalGold += grid[row][col];
            }
        }
        
        int maxGold = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] != 0) {
                    maxGold = max(maxGold, bfsBacktrack(grid, rows, cols, row, col));
                    
                    if (maxGold == totalGold)
                        return totalGold;
                }
            }
        }
        return maxGold;
    }

private:
    const vector<int> DIRECTIONS = {0, 1, 0, -1, 0};

    int bfsBacktrack(vector<vector<int>>& grid,
                      int rows, int cols, int row, int col) {
        queue<tuple<int, int, int, bitset<1024>>> queue;
        bitset<1024> visited;
        int maxGold = 0;
        visited[row * cols + col] = 1;
        queue.push({row, col, grid[row][col], visited});

        while (!queue.empty()) {
            auto [currRow, currCol, currGold, currVis] = queue.front();
            queue.pop();
            maxGold = max(maxGold, currGold);

            for (int direction = 0; direction < 4; direction++) {
                int nextRow = currRow + DIRECTIONS[direction];
                int nextCol = currCol + DIRECTIONS[direction + 1];

                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols &&
                        grid[nextRow][nextCol] != 0 &&
                        !currVis[nextRow * cols + nextCol]) {
                    currVis[nextRow * cols + nextCol] = 1;
                    queue.push({nextRow, nextCol, currGold + grid[nextRow][nextCol], 
                                currVis});
                    currVis[nextRow * cols + nextCol] = 0;
                }
            }
        }
        return maxGold;
    }
};