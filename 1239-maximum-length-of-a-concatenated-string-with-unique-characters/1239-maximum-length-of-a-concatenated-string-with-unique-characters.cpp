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
    int solveMaxLength(int index, vector<string> &arr, string current, int n){
        if(index == n){
            return current.size();
        }
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[index], current)){
            exclude = solveMaxLength(index+1, arr, current, n);
        }
        else{
            include = solveMaxLength(index+1, arr, current+arr[index], n);
            exclude = solveMaxLength(index+1, arr, current, n);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string current = "";
        return solveMaxLength(0, arr, current, n);
    }
};