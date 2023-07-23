class Solution {
    
    public String longestPalindrome(String s) {
        int n = s.length();
        int currMax = 0;
        String currMaxString = "";
        for(int i=0; i<n; i++){
            //odd length
            int left = i;
            int right = i;
            while(left >=0 && right < n && s.charAt(left) == s.charAt(right)){
                if(right-left+1 > currMax){
                    currMax = right-left+1;
                    currMaxString = s.substring(left, right+1);
                }
                left--;
                right++;
            }
            
            //even length
            left = i;
            right = i+1;
            while(left >=0 && right < n && s.charAt(left) == s.charAt(right)){
                if(right-left+1 > currMax){
                    currMax = right-left+1;
                    currMaxString = s.substring(left, right+1);
                }
                left--;
                right++;
            }
        }
        return currMaxString;
    }
}