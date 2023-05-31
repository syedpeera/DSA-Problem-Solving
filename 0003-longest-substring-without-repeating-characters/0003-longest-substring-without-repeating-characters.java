class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int maxLen = 0;
        Map<Character, Integer> map = new HashMap<>();

        while (j < n) {
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);

            if (map.size() == j - i + 1) {
                maxLen = Math.max(maxLen, j - i + 1);
                j++;
            } else if (map.size() < j - i + 1) {
                while (map.size() < j - i + 1) {
                    map.put(s.charAt(i), map.get(s.charAt(i)) - 1);
                    if (map.get(s.charAt(i)) == 0) {
                        map.remove(s.charAt(i));
                    }
                    i++;
                }
                if (map.size() == j - i + 1) {
                    maxLen = Math.max(maxLen, j - i + 1);
                    j++;
                }
            }
        }
        return maxLen;
    }
}