//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] s = br.readLine().trim().split(" ");
            int n = Integer.parseInt(s[0]);
            int m = Integer.parseInt(s[1]);
            int[][] grid = new int[n][m];
            for(int i = 0; i < n; i++){
                String[] S = br.readLine().trim().split(" ");
                for(int j = 0; j < m; j++){
                    grid[i][j] = Integer.parseInt(S[j]);
                }
            }
            Solution obj = new Solution();
            int ans = obj.orangesRotting(grid);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

class Pair{
    int rowIndex;
    int colIndex;
    int time;
    Pair(int rowIndex, int colIndex, int time){
        this.rowIndex = rowIndex;
        this.colIndex = colIndex;
        this.time = time;
    }
}
class Solution
{
    public int orangesRotting(int[][] grid)
    {
        //<<rowIndex, colIndex> , time>
        Queue<Pair> q = new LinkedList<>();
        int rowSize = grid.length;
        int colSize = grid[0].length;
        int visited[][] = new int[rowSize][colSize];
        int countFresh = 0;
        
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<colSize; j++){
                if(grid[i][j] == 2){
                    q.add(new Pair(i, j, 0));
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    visited[i][j] = 1;
                    countFresh++;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        int totalTime = 0;
        int count = 0;
        while(!q.isEmpty()){
            int rowIndex = q.peek().rowIndex;
            int colIndex = q.peek().colIndex;
            int time = q.peek().time;
            q.poll();
            for(int i=0; i<4; i++){
                int newRowIndex = rowIndex + drow[i];
                int newColIndex = colIndex + dcol[i];
                if(newRowIndex >= 0 && newRowIndex < rowSize && newColIndex >=0 && newColIndex < colSize && grid[newRowIndex][newColIndex] == 1 && visited[newRowIndex][newColIndex] == 1){
                    q.add(new Pair(newRowIndex, newColIndex, time+1));
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
}