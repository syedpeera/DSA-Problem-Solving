class Solution {
    public int missingNumber(int[] nums) {
        //swap sort algorithm
        int n=nums.length;
        int i=0;
        while(i<n){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=j){
                return j;
            }
        }
        return n;
    }
}