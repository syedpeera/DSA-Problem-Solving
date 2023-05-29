//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
        vector<int> bfsTraversal;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            bfsTraversal.push_back(curr);
            vector<int> neighbors = adj[curr];
            for(auto neighbor: neighbors){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        return bfsTraversal;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends