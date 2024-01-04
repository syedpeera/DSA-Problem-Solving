class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums.length;
        int result = 0;
        for(int i=0; i<n; i++){
            map.put(nums[i], map.getOrDefault(nums[i],0)+1);
        }
        for(Map.Entry<Integer, Integer> entry: map.entrySet()){
            int freq = entry.getValue();
            
            if(freq == 1){
                return -1;
            }
            result = result + (int)Math.ceil((double)freq/3);
        }
        return result;
    }
}