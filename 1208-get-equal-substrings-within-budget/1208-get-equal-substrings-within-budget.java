class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int N = s.length();
        int maxLen = 0;
        int start = 0;
        int currCost = 0;
        for (int i = 0; i < N; i++) {
            currCost += Math.abs(s.charAt(i) - t.charAt(i));
            while (currCost > maxCost) {
                currCost -= Math.abs(s.charAt(start) - t.charAt(start));
                start++;
            }
            maxLen = Math.max(maxLen, i - start + 1);
        }
        return maxLen;
    }
}