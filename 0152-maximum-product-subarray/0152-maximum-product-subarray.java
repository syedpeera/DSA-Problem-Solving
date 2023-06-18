class Solution {
    public int maxProduct(int[] nums) {
        int n=nums.length;
        int prefix=1;
        int maximumProduct=Integer.MIN_VALUE;
        int suffix=1;
        for(int i=0;i<n;i++){
            prefix *= nums[i];
            maximumProduct = Math.max(maximumProduct, prefix);
            if(nums[i]==0){
                prefix=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            suffix *= nums[i];
            maximumProduct = Math.max(maximumProduct, suffix);
            if(nums[i]==0){
                suffix=1;
            }
        }
        return maximumProduct;
    }
}