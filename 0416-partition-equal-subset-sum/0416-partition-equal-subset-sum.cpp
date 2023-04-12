class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        
        if(sum%2!=0)
        {
            return false;
        }
        else
        {
            return isSubsetSum(nums, n, sum/2);
        }
    }
    
    bool isSubsetSum(vector<int> nums, int n, int sum) {
        vector<bool> prev(sum+1, false);
        vector<bool> curr(sum+1, false);
        prev[0]=true;
        curr[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    curr[j] = prev[j-nums[i-1]] || prev[j];
                }
                else if(nums[i-1]>j){
                    curr[j] = prev[j]; 
                }
            }
            prev=curr;
        }
        return prev[sum];
    }
};