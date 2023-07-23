class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> tFreq = new HashMap<>();
        for(char c: t.toCharArray()){
            tFreq.put(c, tFreq.getOrDefault(c, 0)+1);
        }
        
        int left = 0;
        int required = tFreq.size();
        int minLen = Integer.MAX_VALUE;
        String result = "";
        
        for(int right=0; right<s.length(); right++){
            if(tFreq.containsKey(s.charAt(right))){
                tFreq.put(s.charAt(right), tFreq.get(s.charAt(right))-1);
                if(tFreq.get(s.charAt(right)) == 0){
                    required--;
                }
            }
            
            while(required == 0){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    result = s.substring(left, right+1);
                    //minStart = left;
                }
                
                if(tFreq.containsKey(s.charAt(left))){
                    tFreq.put(s.charAt(left), tFreq.get(s.charAt(left))+1);
                    if(tFreq.get(s.charAt(left)) > 0){
                        required++;
                    }
                }
                left++;
            }
        }
        
        return minLen == Integer.MAX_VALUE? "" :  result;
    }
}