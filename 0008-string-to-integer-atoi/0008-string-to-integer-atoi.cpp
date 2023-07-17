class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        
        //skip leading whitespace
        while(i < n && s[i] == ' '){
            i++;
        }
        
        //check if number is negative or positive
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-')? -1 : 1;
            i++;
        }
        
        //convert digits to integer
        int number = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            //check overflow
            if(number > INT_MAX/10 || (number == INT_MAX/10 && digit > INT_MAX % 10)){
                return (sign == 1)? INT_MAX : INT_MIN;
            }
            
            number = number * 10 + digit;
            i++;
        }
        
        return number * sign;
    }
};