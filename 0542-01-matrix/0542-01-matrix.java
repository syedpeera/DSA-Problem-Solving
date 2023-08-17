class Pair{
    int rIndex;
    int cIndex;
    Pair(int row, int col){
        rIndex = row;
        cIndex = col;
    }
}
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        int dist[][] = new int[m][n];
        Queue<Pair> q = new LinkedList<>();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.add(new Pair(i, j));
                }
                else{
                    dist[i][j] = Integer.MAX_VALUE;
                }
            }
        }
        
        int rowDist[] = {-1, 0, 1, 0};
        int colDist[] = {0, 1, 0, -1};
        
        while(!q.isEmpty()){
            Pair cell = q.poll();
            int rowIndex = cell.rIndex;
            int colIndex = cell.cIndex;
            for(int i=0; i<4; i++){
                int newRowIndex = rowIndex + rowDist[i];
                int newColIndex = colIndex + colDist[i];
                if(newRowIndex >=0 && newRowIndex<m && newColIndex >=0 && newColIndex<n){
                    if(dist[newRowIndex][newColIndex] > dist[rowIndex][colIndex] + 1){
                        dist[newRowIndex][newColIndex] = dist[rowIndex][colIndex] + 1;
                        q.add(new Pair(newRowIndex, newColIndex));
                    }
                }
            }
        }
        return dist;
    }
}