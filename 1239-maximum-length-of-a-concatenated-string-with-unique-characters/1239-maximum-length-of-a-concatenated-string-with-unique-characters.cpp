class Solution {
public:
    bool hasDuplicate(string &s1, string &s2){
        vector<int> charFreq(26, 0);
        //test case: ["aa", "bb"]
        for(char ch: s1){
            if(charFreq[ch - 'a'] > 0){
                return true;
            }
            charFreq[ch - 'a']++;
        }
        
        for(char ch: s2){
            if(charFreq[ch - 'a'] > 0){
                return true;
            }
        }
        return false;
    }
    int solveMaxLength(int index, vector<string> &arr, string current, int n, unordered_map<string, int> &dp){
        if(index == n){
            return current.size();
        }
        if(dp.find(current) != dp.end()){
            return dp[current];
        }
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[index], current)){
            exclude = solveMaxLength(index+1, arr, current, n, dp);
        }
        else{
            include = solveMaxLength(index+1, arr, current+arr[index], n, dp);
            exclude = solveMaxLength(index+1, arr, current, n, dp);
        }
        dp[current] = max(include, exclude);
        return dp[current];
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string current = "";
        unordered_map<string, int> dp;
        return solveMaxLength(0, arr, current, n, dp);
    }
};