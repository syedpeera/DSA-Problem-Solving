class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber > 0){
            columnNumber--;
            result = result + (char)((columnNumber % 26) + 'A');
            columnNumber = columnNumber / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};