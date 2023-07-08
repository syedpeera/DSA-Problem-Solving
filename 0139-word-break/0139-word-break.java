class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean dp[] = new boolean[n+1];
        dp[0] = true;
        Set<String> dict = new HashSet<>(wordDict);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==true && dict.contains(s.substring(j, i))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}