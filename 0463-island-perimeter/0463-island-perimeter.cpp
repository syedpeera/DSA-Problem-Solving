class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4; // Each land cell contributes 4 sides
                    
                    // Check neighboring cells
                    if (i > 0 && grid[i - 1][j] == 1) // Up
                        perimeter -= 2; // If up neighbor is land, subtract 2 (shared side)
                    if (j > 0 && grid[i][j - 1] == 1) // Left
                        perimeter -= 2; // If left neighbor is land, subtract 2 (shared side)
                }
            }
        }
        
        return perimeter;
    }
};
