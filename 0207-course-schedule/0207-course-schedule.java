class Solution {
    public void bfs(int v, ArrayList<ArrayList<Integer>> adj, int inDegree[], ArrayList<Integer> topologicalSort){
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<v; i++){
            if(inDegree[i] == 0){
                q.add(i);
            }
        }
        while(!q.isEmpty()){
            int curr = q.poll();
            topologicalSort.add(curr);
            ArrayList<Integer> neighbors = adj.get(curr);
            for(int neighbor: neighbors){
                if(--inDegree[neighbor] == 0){
                    q.add(neighbor);
                }
            }
        }
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            graph.add(new ArrayList<>());
        }
        for(int[] prerequisite: prerequisites){
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph.get(prerequisiteCourse).add(course);
        }
        
        int inDegree[] = new int[numCourses];
        for(ArrayList<Integer> list: graph){
            for(int element: list){
                inDegree[element]++;
            }
        }
        ArrayList<Integer> topologicalSort = new ArrayList<>();
        bfs(numCourses, graph, inDegree, topologicalSort);
        return topologicalSort.size() == numCourses;
    }
}
