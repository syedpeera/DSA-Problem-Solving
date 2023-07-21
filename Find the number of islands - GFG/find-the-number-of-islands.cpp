//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j-1);
        dfs(grid, i+1, j+1);
        dfs(grid, i+1, j-1);
        dfs(grid, i-1, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int numberOfIslands = 0;
        
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == '1'){
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return numberOfIslands;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends