class Solution {
    public int myAtoi(String s) {
        int i = 0;
        int n = s.length();
        
        //skip leading whitespace
        while(i < n && s.charAt(i) == ' '){
            i++;
        }
        
        //check if number is negative or positive
        int sign = 1;
        if(i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')){
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }
        
        //convert digits to integer
        int number = 0;
        while(i < n && Character.isDigit(s.charAt(i))){
            int digit = s.charAt(i) - '0';
            //check overflow
            if(number > Integer.MAX_VALUE/10 || (number == Integer.MAX_VALUE/10) && (digit > Integer.MAX_VALUE % 10)){
                return (sign == 1)? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            number = number * 10 + digit;
            i++;
        }
        return number * sign;
    }
}