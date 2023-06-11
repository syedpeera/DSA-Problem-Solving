class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited){
        visited[v]=true;
        vector<int> neighbors = adj[v];
        for(int neighbor: neighbors){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> visited(n, false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};