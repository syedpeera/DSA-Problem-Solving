class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        if(s == null || p == null || s.length() < p.length()){
            return result;
        }
        
        int sCount[] = new int[26];
        int pCount[] = new int[26];
        
        int k = p.length();
        for(int i=0; i<k; i++){
            pCount[p.charAt(i) - 'a']++;
        }
        
        for(int i=0; i<k; i++){
            sCount[s.charAt(i) - 'a']++;
        }
        
        if(Arrays.equals(sCount, pCount)){
            result.add(0);
        }
        
        int left = 0;
        for(int right=k; right<s.length(); right++){
            sCount[s.charAt(left) - 'a']--;
            left++;
            
            sCount[s.charAt(right) - 'a']++;
            
            if(Arrays.equals(sCount, pCount)){
                result.add(left);
            }
        }
        return result;
    }
}