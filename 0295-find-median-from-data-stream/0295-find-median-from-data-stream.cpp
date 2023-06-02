class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() && maxHeap.empty()){
            maxHeap.push(num); 
        }
        else{
            if(num>maxHeap.top()){
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if((n1-n2)==2 || (n1-n2)==-2){
            if(n1>n2){
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
            }
            else{
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
            }
        }
    }
    
    double findMedian() {
        int n1 = maxHeap.size();
        int n2 = minHeap.size();
        if((n1+n2)%2==0){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        else if(n1>n2){
            return (double)maxHeap.top();
        }
        else{
            return (double)minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */