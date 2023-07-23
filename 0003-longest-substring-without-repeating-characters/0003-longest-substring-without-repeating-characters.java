class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        int n = s.length();
        int maxLen = 0;
        Set<Character> uniqueCharacters = new HashSet<>();
        while(right < n){
            if(!uniqueCharacters.contains(s.charAt(right))){
                uniqueCharacters.add(s.charAt(right));
                maxLen = Math.max(maxLen, right-left+1);
                right++;
            }
            else{
                uniqueCharacters.remove(s.charAt(left));
                left++;
            }
        }
        return maxLen;
    }
}