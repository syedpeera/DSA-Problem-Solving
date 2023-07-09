class Solution {
    public int characterReplacement(String s, int k) {
        int maxLen = 0;
        int maxCount = 0;
        int i = 0;
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        for(int j=0;j<n;j++){
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0)+1);
            
            maxCount = Math.max(maxCount, map.get(s.charAt(j)));
            
            if(((j-i+1) - maxCount) > k){
                map.put(s.charAt(i), map.get(s.charAt(i))-1);
                i++;
            }
            
            maxLen = Math.max(maxLen, j-i+1);
        }
        return maxLen;
    }
}