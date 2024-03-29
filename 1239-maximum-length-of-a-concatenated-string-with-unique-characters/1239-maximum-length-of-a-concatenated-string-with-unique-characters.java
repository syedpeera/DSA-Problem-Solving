class Solution {
    public boolean hasDuplicate(String s1, String s2){
        int charFreq[] = new int[26];
        for(char ch: s1.toCharArray()){
            if(charFreq[ch - 'a'] > 0){
                return true;
            }
            charFreq[ch - 'a']++;
        }
        for(char ch: s2.toCharArray()){
            if(charFreq[ch - 'a'] > 0){
                return true;
            }
        }
        return false;
    }
    public int solveMaxLength(int index, List<String> arr, String current, int n, Map<String, Integer> dp){
        if(index == n){
            return current.length();
        }
        if(dp.containsKey(current)){
            return dp.get(current);
        }
        
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr.get(index), current)){
            exclude = solveMaxLength(index+1, arr, current, n, dp);
        }
        else{
            include = solveMaxLength(index+1, arr, current + arr.get(index), n, dp);
            exclude = solveMaxLength(index+1, arr, current, n, dp);
        }
        dp.put(current, Math.max(include, exclude));
        return dp.get(current);
    }
    public int maxLength(List<String> arr) {
        int n = arr.size();
        String current = "";
        Map<String, Integer> dp = new HashMap<>();
        return solveMaxLength(0, arr, current, n, dp);
    }
}