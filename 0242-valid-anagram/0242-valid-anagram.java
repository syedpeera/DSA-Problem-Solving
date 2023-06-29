class Solution {
    public boolean isAnagram(String s, String t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1!=n2){
            return false;
        }
        Map<Character, Integer> map = new HashMap<>();
        for(int i=0;i<n1;i++){
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0)+1);
        }
        for(int i=0;i<n2;i++){
            if(!map.containsKey(t.charAt(i))){
                return false;
            }
            map.put(t.charAt(i), map.get(t.charAt(i))-1);
            if(map.get(t.charAt(i))==0){
                map.remove(t.charAt(i));
            }
        }
        return map.isEmpty();
    }
}