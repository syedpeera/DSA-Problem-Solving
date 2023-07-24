class Solution {
    public int cielBinarySearch(List<Integer> temp, int target){
        int left = 0;
        int right = temp.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(temp.get(mid) == target){
                return mid;
            }
            else if(temp.get(mid) < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
    public int lengthOfLIS(int[] nums) {
        List<Integer> temp = new ArrayList<>();
        temp.add(nums[0]);
        
        for(int i=1; i<nums.length; i++){
            if(nums[i] > temp.get(temp.size()-1)){
                temp.add(nums[i]);
            }
            else{
                int index = cielBinarySearch(temp, nums[i]);
                temp.set(index, nums[i]);
            }
        }
        return temp.size();
    }
}