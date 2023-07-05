class Solution {
    public String reverseWords(String s) {
        int n = s.length();
        int i = 0;
        StringBuilder result = new StringBuilder();
        while(i<n){
            while(i<n && s.charAt(i)==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            int j = i + 1;
            while(j<n && s.charAt(j)!=' '){
                j++;
            }
            String str = s.substring(i, j);
            if(result.length()==0){
                result.append(str);
            }
            else{
                result.insert(0, str+' ');
            }
            i = j + 1;
        }
        return result.toString();
    }
}