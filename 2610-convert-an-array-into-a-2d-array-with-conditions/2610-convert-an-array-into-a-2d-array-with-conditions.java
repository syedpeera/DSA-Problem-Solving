class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        List<List<Integer>> result = new ArrayList<>();
        for(int i=0; i<n; i++){
            int freq = map.getOrDefault(nums[i], 0);
            if(freq == result.size()){
                result.add(new ArrayList<>());
            }
            result.get(freq).add(nums[i]);
            map.put(nums[i], freq+1);
        }
        return result;
    }
}