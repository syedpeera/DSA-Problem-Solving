class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n=nums.length;
        List<Integer> result = new ArrayList<>();
        for(int i=0;i<n;i++){
            int index = Math.abs(nums[i])-1;
            if(nums[index]<0){
                result.add(Math.abs(nums[i]));
            }
            nums[index] = -nums[index];
        }
        return result;
    }
}