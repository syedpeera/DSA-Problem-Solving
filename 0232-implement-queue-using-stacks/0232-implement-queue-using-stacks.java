class MyQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    
    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
        if(stack1.isEmpty()){
            stack1.add(x);
        }
        else{
            while(!stack1.isEmpty()){
                stack2.add(stack1.peek());
                stack1.pop();
            }
            
            stack1.add(x);
            
            while(!stack2.isEmpty()){
                stack1.add(stack2.peek());
                stack2.pop();
            }
        }
    }
    
    public int pop() {
        int element = stack1.peek();
        stack1.pop();
        return element;
    }
    
    public int peek() {
        return stack1.peek();
    }
    
    public boolean empty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */