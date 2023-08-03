class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        int n = values.size();
        for(int i=0; i<n; i++){
            while(num >= values[i]){
                num = num - values[i];
                result = result + symbols[i];
            }
        }
        return result;
    }
};