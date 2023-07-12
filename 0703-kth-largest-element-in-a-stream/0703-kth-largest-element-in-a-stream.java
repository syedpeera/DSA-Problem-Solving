class KthLargest {
    private int k;
    private PriorityQueue<Integer> minHeap;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        minHeap = new PriorityQueue<>();
        for(int num: nums){
            minHeap.add(num);
        }
        
        while(minHeap.size() > k){
            minHeap.poll();
        }
    }
    
    public int add(int val) {
        minHeap.add(val);
        if(minHeap.size() > k){
            minHeap.poll();
        }
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */