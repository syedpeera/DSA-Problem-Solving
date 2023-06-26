class Solution {
    public void reverse(int nums[], int left, int right){
        while(left<=right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int index1=-1;
        int index2=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index1 = i-1;
                break;
            }
        }
        if(index1==-1){
            reverse(nums, 0, n-1);
        }
        else{
            for(int i=n-1;i>index1;i--){
                if(nums[i]>nums[index1]){
                    index2 = i;
                    break;
                }
            }
            int temp = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = temp;
            reverse(nums, index1+1, n-1);
        }
    }
}