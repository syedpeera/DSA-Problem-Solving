class Solution {
    public int maxProfit(int[] prices) {
        int minimumSoFar = prices[0];
        int maxProfit = 0;
        for(int i=0;i<prices.length;i++){
            minimumSoFar = Math.min(minimumSoFar, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i]-minimumSoFar);
        }
        return maxProfit;
    }
}