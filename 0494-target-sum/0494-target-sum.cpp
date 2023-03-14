class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        int countZeros = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                countZeros++;
            }
            sum=sum+nums[i];
        }
        if(target>sum){
            return 0;
        }
        if((target+sum)%2!=0){
            return 0;
        }
        int finalTarget = (target+sum)/2;
        if(finalTarget<0){
            return 0;
        }
        int dp[n+1][finalTarget+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<finalTarget+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<finalTarget+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                if(nums[i-1]>j || nums[i-1]==0){
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return (int)pow(2,countZeros)*dp[n][finalTarget];
    }
};