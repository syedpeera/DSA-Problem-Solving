class Solution {
    public int longestConsecutive(int[] nums) {
        int n=nums.length;
        int result=0;
        HashSet<Integer> set = new HashSet<>();
        for(int i=0;i<n;i++){
            set.add(nums[i]);
        }
        for(int i=0;i<n;i++){
            int currentElement=nums[i];
            int previousElement=currentElement-1;
            int count=1;
            if(!set.contains(previousElement)){
                while(set.contains(currentElement+1)){
                    currentElement++;
                    count++;
                }
            }
            result=Math.max(result, count);
        }
        return result;
    }
}