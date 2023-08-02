class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        
        int n = s.size();
        int number = 0;
        for(int i=0; i<n-1; i++){
            if(map[s[i]] < map[s[i+1]]){
                number = number - map[s[i]];
            }
            else{
                number = number + map[s[i]];
            }
        }
        number = number + map[s[n-1]];
        return number;
    }
};