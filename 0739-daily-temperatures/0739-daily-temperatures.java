class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int hottest = Integer.MIN_VALUE;
        int result[] = new int[n];
        for(int i=n-1; i>=0; i--){
            if(temperatures[i] >= hottest){
                hottest = temperatures[i];
            }
            else{
                int it = i+1;
                while(temperatures[it] <= temperatures[i]){
                    it = it + result[it];
                }
                result[i] = it - i;
            }
        }
        return result;
    }
}