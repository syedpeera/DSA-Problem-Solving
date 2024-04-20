class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmlands;
        int m = land.size();
        int n = land[0].size();

        // Define DFS function
        auto dfs = [&](int r, int c) {
            int r2 = r;
            int c2 = c;

            // Find the bottom right corner of the farmland group
            while (r2 < m && land[r2][c] == 1) {
                while (c2 < n && land[r2][c2] == 1) {
                    c2++;
                }
                r2++;
            }

            // Mark visited cells as 0
            for (int i = r; i < r2; i++) {
                for (int j = c; j < c2; j++) {
                    land[i][j] = 0;
                }
            }

            // Add the coordinates to the result
            farmlands.push_back({r, c, r2 - 1, c2 - 1});
        };

        // Iterate through the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }

        return farmlands;
    }
};