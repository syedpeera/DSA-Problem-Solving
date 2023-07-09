class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        Map<String, List<String>> groupAnagrams = new HashMap<>();
        for(String word: strs){
            int charCount[] = new int[26];
            for(char c: word.toCharArray()){
                charCount[c - 'a']++;
            }
            StringBuilder sb = new StringBuilder();
            for(int charVal: charCount){
                sb.append(charVal);
                sb.append("#");
            }
            String key = sb.toString();
            if(!groupAnagrams.containsKey(key)){
                groupAnagrams.put(key, new ArrayList<>());
            }
            groupAnagrams.get(key).add(word);
        }
        List<List<String>> result = new ArrayList<>();
        for(Map.Entry<String, List<String>> entry: groupAnagrams.entrySet()){
            result.add(entry.getValue());
        }
        return result;
    }
}