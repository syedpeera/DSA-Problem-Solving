class Solution {
public:
    bool dfs(int v, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& callStack) {
        visited[v] = true;
        callStack[v] = true;
        vector<int>& neighbors = graph[v];
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, callStack)) {
                    return true;
                }
            } else if (callStack[neighbor]) {
                return true;
            }
        }
        callStack[v] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (vector<int>& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];
            graph[prerequisiteCourse].push_back(course);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> callStack(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, callStack)) {
                    return false;
                }
            }
        }
        return true;
    }
};
