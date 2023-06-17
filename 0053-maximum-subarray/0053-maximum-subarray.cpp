class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currSum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            maxSum=max(maxSum, currSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};