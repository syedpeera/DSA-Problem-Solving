//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadanes(vector<int> sum){
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0;i<sum.size();i++){
            currSum += sum[i];
            maxSum = max(maxSum, currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
    int maximumSumRectangle(int row, int col, vector<vector<int>> input) {
        int maxSum = INT_MIN;
        for(int cStart=0;cStart<col;cStart++){
            vector<int> sum(row, 0);
            for(int cEnd=cStart;cEnd<col;cEnd++){
                for(int i=0;i<row;i++){
                    sum[i] += input[i][cEnd];
                }
                int currMaxSum = kadanes(sum);
                maxSum = max(maxSum, currMaxSum);
            }
        }
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends