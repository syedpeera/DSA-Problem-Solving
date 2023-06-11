class Solution {
    /*
    public void dfs(int v, List<List<Integer>> adj, boolean visited[]){
        visited[v]=true;
        List<Integer> neighbors = adj.get(v);
        for(int neighbor: neighbors){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }*/
    public void bfs(int v, List<List<Integer>> adj, boolean visited[]){
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(v);
        visited[v]=true;
        while(!queue.isEmpty()){
            int curr = queue.poll();
            for(int neighbor: adj.get(curr)){
                if(!visited[neighbor]){
                    queue.add(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj.get(i).add(j);
                }
            }
        }
        int count=0;
        boolean visited[] = new boolean[n];
        /*
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }*/
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
}