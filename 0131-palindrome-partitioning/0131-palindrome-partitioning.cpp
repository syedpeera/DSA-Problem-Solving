class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solvePartition(string &s, int start, vector<string> &current, vector<vector<string>> &result){
        if(start == s.size()){
            result.push_back(current);
            return;
        }
        for(int end=start; end<s.size(); end++){
            if(isPalindrome(s, start, end)){
                current.push_back(s.substr(start, end-start+1));
                solvePartition(s, end+1, current, result);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        solvePartition(s, 0, current, result);
        return result;
    }
};