class Solution {
    public int pivotIndex(int[] nums) {
        int n = nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        int leftSum=0;
        for(int i=0;i<n;i++){
            sum = sum - nums[i];
            if(leftSum == sum){
                return i;
            }
            leftSum = leftSum + nums[i];
        }
        return -1;
    }
}