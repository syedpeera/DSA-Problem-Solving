class Solution {
    public int majorityElement(int[] nums) {
        int candidate = 0;
        int count = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
}