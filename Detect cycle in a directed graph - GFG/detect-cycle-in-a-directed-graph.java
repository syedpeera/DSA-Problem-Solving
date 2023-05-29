//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            ArrayList<ArrayList<Integer>> list = new ArrayList<>();
            int V = sc.nextInt();
            int E = sc.nextInt();
            for (int i = 0; i < V; i++)
                list.add(i, new ArrayList<Integer>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                list.get(u).add(v);
            }
            if (new Solution().isCyclic(V, list) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}
// } Driver Code Ends


/*Complete the function below*/

class Solution {
    public boolean isCyclic(int v, ArrayList<ArrayList<Integer>> adj) {
        boolean visited[] = new boolean[v];
        boolean callStack[] = new boolean[v];
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, callStack)){
                    return true;
                }
            }
        }
        return false;
    }
    public boolean dfs(int v, ArrayList<ArrayList<Integer>> adj, boolean visited[], boolean callStack[]){
        visited[v]=true;
        callStack[v]=true;
        ArrayList<Integer> neighbors = adj.get(v);
        for(int neighbor: neighbors){
            if(!visited[neighbor]){
                if(dfs(neighbor, adj, visited, callStack)){
                    return true;
                }
            }
            else if(callStack[neighbor]){
               return true;
            }
        }
        callStack[v]=false;
        return false;
    }
}