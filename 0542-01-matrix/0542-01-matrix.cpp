class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        //rowIndex, colIndex
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<int> rowDist = {-1, 0, 1, 0};
        vector<int> colDist = {0, 1, 0, -1};
        
        while(!q.empty()){
            int rowIndex = q.front().first;
            int colIndex = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int newRowIndex = rowIndex + rowDist[i];
                int newColIndex = colIndex + colDist[i];
                if(newRowIndex >=0 && newRowIndex<m && newColIndex >=0 && newColIndex<n){
                    if(dist[newRowIndex][newColIndex] > dist[rowIndex][colIndex] + 1){
                        dist[newRowIndex][newColIndex] = dist[rowIndex][colIndex] + 1;
                        q.push({newRowIndex, newColIndex});
                    }
                }
            }
        }
        return dist;
    }
};