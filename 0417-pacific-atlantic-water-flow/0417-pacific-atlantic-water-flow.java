class Solution {
    public void dfs(int[][] heights, int i, int j, int prev, int[][] ocean){
        if(i<0 || j<0 || i>=heights.length || j>=heights[0].length){
            return;
        }
        if(ocean[i][j]==1){
            return;
        }
        if(heights[i][j]<prev){
            return;
        }
        ocean[i][j]=1;
        dfs(heights, i+1, j, heights[i][j], ocean);
        dfs(heights, i-1, j, heights[i][j], ocean);
        dfs(heights, i, j+1, heights[i][j], ocean);
        dfs(heights, i, j-1, heights[i][j], ocean);
    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        int row=heights.length;
        int col=heights[0].length;
        //intitialize with 0
        int[][] pacific = new int[row][col];
        int[][] atlantic = new int[row][col];
        //reachable from pacific ocean
        for(int i=0;i<row;i++){
            dfs(heights, i, 0, Integer.MIN_VALUE, pacific);
        }
        for(int j=0;j<col;j++){
            dfs(heights, 0, j, Integer.MIN_VALUE, pacific);
        }
        //reachable from atlantic ocean
        for(int i=0;i<row;i++){
            dfs(heights, i, col-1, Integer.MIN_VALUE, atlantic);
        }
        for(int j=0;j<col;j++){
            dfs(heights, row-1, j, Integer.MIN_VALUE, atlantic);
        }
        
        //find cells that can flow to both these
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    List<Integer> cell = new ArrayList<>();
                    cell.add(i);
                    cell.add(j);
                    result.add(cell);
                }
            }
        }
        return result;
    }
}