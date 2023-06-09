class Solution {
    public boolean dfs(int v, ArrayList<ArrayList<Integer>> graph, boolean[] visited, boolean[] callStack ){
        visited[v]=true;
        callStack[v]=true;
        ArrayList<Integer> neighbors = graph.get(v);
        for(int neighbor: neighbors){
            if(!visited[neighbor]){
                if(dfs(neighbor, graph, visited, callStack)){
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
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            graph.add(new ArrayList<>());
        }
        for(int[] prerequisite: prerequisites){
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph.get(course).add(prerequisiteCourse);
        }
        boolean visited[] = new boolean[numCourses];
        boolean callStack[] = new boolean[numCourses];
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i, graph, visited, callStack)){
                    return false;
                }
            }
        }
        return true;
    }
}