class Solution {
    public int arraySign(int[] nums) {
        int n = nums.length;
        int product = 1;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                return 0;
            }
            product = product * ((nums[i] > 0)? 1 : -1);
        }
        return product;
    }
}