class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> sumFreq = new HashMap<>();
        sumFreq.put(0, 1);
        int count = 0;
        int sum = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            sum = sum + nums[i];
            
            int compliment = sum - k;
            
            if(sumFreq.containsKey(compliment)){
                count = count + sumFreq.get(compliment);
            }
            
            sumFreq.put(sum, sumFreq.getOrDefault(sum, 0)+1);
        }
        return count;
    }
}