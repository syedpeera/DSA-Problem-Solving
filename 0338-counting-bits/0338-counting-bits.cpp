class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++){
            int digit = (i & 1);
            dp[i] = digit + dp[i>>1];
        }
        return dp;
    }
};