class Solution {
public:
 bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        // Build adjacency list representation of the graph
        std::vector<std::unordered_set<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].insert(edge[1]);
            adjList[edge[1]].insert(edge[0]);
        }
        
        // Initialize visited set
        std::unordered_set<int> visited;
        
        // Perform DFS
        return dfs(adjList, visited, source, destination);
    }
    
    bool dfs(const std::vector<std::unordered_set<int>>& adjList, std::unordered_set<int>& visited, int current, int destination) {
        // If current node is the destination, return true
        if (current == destination) return true;
        
        // Mark current node as visited
        visited.insert(current);
        
        // Explore neighbors
        for (int neighbor : adjList[current]) {
            // If neighbor has not been visited, recursively explore it
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(adjList, visited, neighbor, destination)) return true;
            }
        }
        
        // If destination not found, return false
        return false;
    }
};