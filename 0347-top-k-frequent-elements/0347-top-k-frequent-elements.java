class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Pair<Integer, Integer>> minHeap = new PriorityQueue<>((a,b)-> a.getKey() - b.getKey());
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            frequencyMap.put(nums[i], frequencyMap.getOrDefault(nums[i],0)+1);
        }
        for(Map.Entry<Integer, Integer> entry: frequencyMap.entrySet()){
            int frequency = entry.getValue();
            int element = entry.getKey();
            minHeap.add(new Pair<>(frequency, element));
            if(minHeap.size()>k){
                minHeap.poll();
            }
        }
        int result[] = new int[k];
        int i=0;
        while(!minHeap.isEmpty()){
            result[i++]=minHeap.poll().getValue();
        }
        return result;
    }
}