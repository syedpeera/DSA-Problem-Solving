class Solution {
    public int jump(int[] nums) {
        int maxReachable = 0;
        int jumps = 0;
        int current = 0;
        int n = nums.length;
        for(int i=0; i<n-1; i++){
            maxReachable = Math.max(maxReachable, i+nums[i]);
            if(current == i){
                current = maxReachable;
                jumps++;
            }
        }
        return jumps;
    }
}