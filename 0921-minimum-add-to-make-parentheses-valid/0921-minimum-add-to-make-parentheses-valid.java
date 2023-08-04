class Solution {
    public int minAddToMakeValid(String s) {
        int n = s.length();
        int bracket = 0;
        int result = 0;
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            bracket = bracket + (ch == '('? 1: -1);
            
            if(bracket == -1){
                result++;
                bracket++;
            }
        }
        return result+bracket;
    }
}