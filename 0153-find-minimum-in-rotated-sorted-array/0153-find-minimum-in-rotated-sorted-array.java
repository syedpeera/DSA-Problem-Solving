class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int left = 0;
        int right = n-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            int next = (mid+1)%n;
            int prev = (mid-1+n)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]){
                return nums[mid];
            }
            else if(nums[left]<=nums[mid] && nums[mid]>=nums[right]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return 0;
    }
}