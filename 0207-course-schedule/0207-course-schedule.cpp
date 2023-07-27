class Solution {
public:
    void bfs(int v, vector<vector<int>> &adj, vector<int> &inDegree, vector<int> &topologicalSort){
        queue<int> q;
        for(int i=0; i<v; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topologicalSort.push_back(curr);
            vector<int> neighbors = adj[curr];
            for(int neighbor: neighbors){
                if(--inDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[course].push_back(prerequisiteCourse);
        }
        
        vector<int> inDegree(numCourses, 0);
        for(vector<int> list: graph){
            for(int element: list){
                inDegree[element]++;
            }
        }
        vector<int> topologicalSort;
        bfs(numCourses, graph, inDegree, topologicalSort);
        return topologicalSort.size() == numCourses;
    }
};