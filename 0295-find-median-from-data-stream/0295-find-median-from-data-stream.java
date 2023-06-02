class MedianFinder {
    private PriorityQueue<Integer> minHeap;
    private PriorityQueue<Integer> maxHeap;
    public MedianFinder() {
        minHeap = new PriorityQueue<>((a,b) -> a-b);
        maxHeap = new PriorityQueue<>((a,b) -> b-a);
    }
    
    public void addNum(int num) {
        if(minHeap.isEmpty() && maxHeap.isEmpty()){
            maxHeap.add(num);
        }
        else{
            if(num>maxHeap.peek()){
                minHeap.add(num);
            }   
            else{
                maxHeap.add(num);
            }
        }
        
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if((n1-n2)==2 || (n1-n2)==-2){
            if(n1>n2){
                int element = maxHeap.poll();
                minHeap.add(element);
            }
            else{
                int element = minHeap.poll();
                maxHeap.add(element);
            }
        }
    }
    
    public double findMedian() {
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if((n1+n2)%2==0){
            return (minHeap.peek()+maxHeap.peek())/2.0;
        }
        else if(n1>n2){
            return (double)maxHeap.peek();
        }
        else{
            return (double)minHeap.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */