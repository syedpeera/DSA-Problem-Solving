class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        dp[0] = 1;
        dp[1] = (s[0] != '0')? 1: 0;
        
        for(int i = 2; i <= n; i++){
            int oneDigit = stoi(s.substr(i-1, 1));
            int twoDigits = stoi(s.substr(i-2, 2));
            
            if(oneDigit >= 1 && oneDigit <= 9){
                dp[i] += dp[i-1];
            }
            
            if(twoDigits >= 10 && twoDigits <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};