class Solution {
    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        
        int n = s.length();
        int number = 0;
        for(int i=0; i<n-1; i++){
            if(map.get(s.charAt(i)) < map.get(s.charAt(i+1))){
                number = number - map.get(s.charAt(i));
            }
            else{
                number = number + map.get(s.charAt(i));
            }
        }
        number = number + map.get(s.charAt(n-1));
        return number;
    }
}