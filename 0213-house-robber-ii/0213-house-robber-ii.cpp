class Solution {
public:
    int robHelper(vector<int> &nums, int start, int n){
        int prev1 = 0;
        int prev2 = 0;
        for(int i=start;i<n;i++){
            int temp = prev1;
            prev1 = max(prev1, prev2+nums[i]);
            prev2 = temp;
        }
        return prev1;
    }
    int rob(vector<int> &nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return nums[0];
        }
        int robFirst = robHelper(nums, 0, n-1);
        int robLast = robHelper(nums, 1, n);
        return max(robFirst, robLast);
    }
};