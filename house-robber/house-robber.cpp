class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;
        for(int i=0;i<nums.size();i++){
            int temp = prev1;
            prev1 = max(prev1, prev2+nums[i]);
            prev2 = temp;
        }
        return prev1;
    }
};