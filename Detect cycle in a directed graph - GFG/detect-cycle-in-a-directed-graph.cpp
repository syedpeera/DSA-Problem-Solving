//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int v, vector<int>* adj, vector<bool>& visited, vector<bool>& callStack) {
        visited[v] = true;
        callStack[v] = true;
        
        vector<int>& neighbors = adj[v];
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, callStack)) {
                    return true;
                }
            } else if (callStack[neighbor]) {
                return true;
            }
        }
        
        callStack[v] = false;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[]) {
        vector<bool> visited(v, false);
        vector<bool> callStack(v, false);
        
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, callStack)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends