class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        
        for(int j=0;j<n;j++){
            prev[j] = 1;
        }
        for(int i=1;i<m;i++){
            curr[0] = 1;
            for(int j=1;j<n;j++){
                curr[j] = curr[j-1] + prev[j];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};