class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int result[] = new int[n-k+1];
        Deque<Integer> dq = new ArrayDeque<>();
        int j = 0;
        for(int i=0; i<k; i++){
            while(!dq.isEmpty() && dq.peekLast() < nums[i]){
                dq.pollLast();
            }
            
            dq.addLast(nums[i]);
        }
        result[j++] = dq.peek();
        for(int i=k; i<n; i++){
            if(dq.peek() == nums[i-k]){
                dq.poll();
            }
            
            while(!dq.isEmpty() && dq.peekLast() < nums[i]){
                dq.pollLast();
            }
            
            dq.addLast(nums[i]);
            
            result[j++] = dq.peek();
        }
        return result;
    }
}