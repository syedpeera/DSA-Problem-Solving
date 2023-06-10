class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<int>>& ocean) {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size()) {
            return;
        }
        if (ocean[i][j] == 1) {
            return;
        }
        if (heights[i][j] < prev) {
            return;
        }
        ocean[i][j] = 1;
        dfs(heights, i + 1, j, heights[i][j], ocean);
        dfs(heights, i - 1, j, heights[i][j], ocean);
        dfs(heights, i, j + 1, heights[i][j], ocean);
        dfs(heights, i, j - 1, heights[i][j], ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        int row = heights.size();
        int col = heights[0].size();
        // Initialize with 0
        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> atlantic(row, vector<int>(col, 0));

        // Reachable from Pacific Ocean
        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, INT_MIN, pacific);
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, INT_MIN, pacific);
        }

        // Reachable from Atlantic Ocean
        for (int i = 0; i < row; i++) {
            dfs(heights, i, col - 1, INT_MIN, atlantic);
        }
        for (int j = 0; j < col; j++) {
            dfs(heights, row - 1, j, INT_MIN, atlantic);
        }

        // Find cells that can flow to both oceans
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }

        return result;   
    }
};