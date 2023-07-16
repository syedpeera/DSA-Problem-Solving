class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int n = nums.length;
        int j = 0, k = 0;
        int closestSum = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for(int i=0; i<n; i++){
            j = i+1;
            k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(Math.abs(sum - target) < Math.abs(closestSum - target)){
                    closestSum = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
        }
        return closestSum;
    }
}