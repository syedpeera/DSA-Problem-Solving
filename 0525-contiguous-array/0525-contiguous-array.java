class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int result = 0;
        int sum = 0;
        //Sum and Index
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        for(int i=0; i<n; i++){
            sum = sum + ((nums[i] == 0)? (-1) : 1);
            if(map.containsKey(sum)){
                result = Math.max(result, i - map.get(sum));
            }
            else{
                map.put(sum, i);
            }
        }
        return result;
    }
}