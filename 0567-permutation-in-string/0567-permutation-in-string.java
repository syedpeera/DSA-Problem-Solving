class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if(n1 > n2){
            return false;
        }
        
        int s1Freq[] = new int[26];
        int s2Freq[] = new int[26];
        
        int k=n1;
        for(int i=0; i<k; i++){
            s1Freq[s1.charAt(i) - 'a']++;
            s2Freq[s2.charAt(i) - 'a']++;
        }
        
        if(Arrays.equals(s1Freq, s2Freq)){
            return true;
        }
        
        int left = 0;
        for(int right=k; right<n2; right++){
            s2Freq[s2.charAt(left) - 'a']--;
            left++;
            s2Freq[s2.charAt(right) - 'a']++;
            
            if(Arrays.equals(s1Freq, s2Freq)){
                return true;
            }
        }
        return false;
    }
}