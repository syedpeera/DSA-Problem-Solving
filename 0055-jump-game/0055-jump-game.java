class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int maxReachable = 0;
        for(int i=0;i<n;i++){
            if(maxReachable < i){
                return false;
            }
            maxReachable = Math.max(maxReachable, i+nums[i]);
        }
        return true;
    }
}
