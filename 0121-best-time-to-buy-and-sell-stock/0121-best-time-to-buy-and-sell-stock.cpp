class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumSoFar = prices[0];
        int maxProfit = 0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            minimumSoFar = min(minimumSoFar, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minimumSoFar);
        }
        return maxProfit;
    }
};