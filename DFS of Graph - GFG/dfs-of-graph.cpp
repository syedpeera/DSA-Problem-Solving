//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs(int v, vector<int>* adj, vector<bool>& visited, vector<int>& dfsTraversal) {
        visited[v] = true;
        dfsTraversal.push_back(v);
        vector<int> neighbors = adj[v];
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, dfsTraversal);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<bool> visited(v, false);
        vector<int> dfsTraversal;
    
        dfs(0, adj, visited, dfsTraversal);
    
        return dfsTraversal;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends