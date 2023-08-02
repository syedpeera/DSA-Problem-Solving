class Solution {
    public void swap(int nums[], int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public void solvePermute(List<List<Integer>> result, int nums[], int start, int end){
        if(start == end){
            List<Integer> permutation = new ArrayList<>();
            for (int num : nums) {
                permutation.add(num);
            }
            result.add(permutation);
            return;
        }
        
        for(int i = start; i <= end; i++){
            swap(nums, start, i);
            solvePermute(result, nums, start + 1, end);
            swap(nums, start, i);
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        solvePermute(result, nums, 0, n - 1);
        return result;
    }
}