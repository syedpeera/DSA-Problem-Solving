class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s.charAt(i)>='A' && s.charAt(i)<='Z'){
                sb.append(Character.toLowerCase(s.charAt(i)));
            }
            else if(s.charAt(i)>='a' && s.charAt(i)<='z'){
                sb.append(s.charAt(i));
            }
            else if(s.charAt(i)>='0' && s.charAt(i)<='9'){
                sb.append(s.charAt(i));
            }
        }
        int left=0;
        int right=sb.length()-1;
        while(left<=right){
            if(sb.charAt(left)!=sb.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}