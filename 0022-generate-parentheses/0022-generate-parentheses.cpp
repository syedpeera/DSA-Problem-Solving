class Solution {
public:
    void generateParenthesis(vector<string>& result, string current, int open, int close, int n){
        if(current.size()==2*n){
            result.push_back(current);
            return;
        }
        if(open < n){
            generateParenthesis(result, current+'(', open+1, close, n);
        }
        if(close < open){
            generateParenthesis(result, current+')', open, close+1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesis(result, "", 0, 0, n);
        return result;
    }
};