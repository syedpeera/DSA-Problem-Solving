class Solution {
    public void swap(int nums[], int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    public List<Integer> findDuplicates(int[] nums) {
        int n=nums.length;
        List<Integer> result = new ArrayList<>();
        int i=0;
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums, i, nums[i]-1);
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!=j+1){
                result.add(nums[j]);
            }
        }
        return result;
    }
}