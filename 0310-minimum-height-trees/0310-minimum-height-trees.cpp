class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Special case: only one node
        
        vector<vector<int>> adjList(n);
        vector<int> degrees(n, 0);
        
        // Create adjacency list and compute degrees
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }
        
        queue<int> leaves;
        // Add all leaf nodes to the queue
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) leaves.push(i);
        }
        
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adjList[leaf]) {
                    if (--degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }
        
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
        return result;
    }
};