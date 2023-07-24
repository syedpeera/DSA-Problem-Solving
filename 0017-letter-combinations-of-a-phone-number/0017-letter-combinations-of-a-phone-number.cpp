class Solution {
public:
    void backtrack(string &digits, int index, unordered_map<char, string> &digitToLetters, string &current, vector<string> &result){
        if(index == digits.size()){
            result.push_back(current);
            return;
        }
        
        string letters = digitToLetters[digits[index]];
        for(int i=0; i<letters.size(); i++){
            current.push_back(letters[i]);
            backtrack(digits, index+1, digitToLetters, current, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0){
            return result;
        }
        
        unordered_map<char, string> digitToLetters = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        
        string current;
        backtrack(digits, 0, digitToLetters, current, result);
        
        return result;
    }
};