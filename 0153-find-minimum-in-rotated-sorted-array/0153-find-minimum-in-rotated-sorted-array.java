class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int left = 0;
        int right = n-1;
        int result = Integer.MAX_VALUE;
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(nums[left] <= nums[mid]){
                result = Math.min(result, nums[left]);
                left = mid + 1;
            }
            else{
                result = Math.min(result, nums[mid]);
                right = mid - 1;
            }
        }
        return result;
    }
}