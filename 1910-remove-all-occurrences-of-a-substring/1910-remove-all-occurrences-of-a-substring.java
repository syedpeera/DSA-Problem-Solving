class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder result = new StringBuilder();
        for(int i=0; i<s.length(); i++){
            result.append(s.charAt(i));
            if(result.length() >= part.length() && result.substring(result.length() - part.length()).equals(part)){
                int n = part.length();
                while(n > 0){
                    result.deleteCharAt(result.length()-1);
                    n = n - 1;
                }
            }
        }
        return result.toString();
    }
}