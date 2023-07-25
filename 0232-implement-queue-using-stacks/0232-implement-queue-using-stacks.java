class MyQueue {
    private Stack<Integer> stack1;
    private Stack<Integer> stack2;
    
    public MyQueue() {
        stack1 = new Stack<>();
        stack2 = new Stack<>();
    }
    
    public void push(int x) {
        stack1.add(x);
    }
    
    public int pop() {
        if(!stack2.isEmpty()){
            int element = stack2.peek();
            stack2.pop();
            return element;
        }
        else{
            while(!stack1.isEmpty()){
                stack2.add(stack1.peek());
                stack1.pop();
            }
            
            int element = stack2.peek();
            stack2.pop();
            return element;
        }
    }
    
    public int peek() {
        if(!stack2.isEmpty()){
            return stack2.peek();
        }
        else{
            while(!stack1.isEmpty()){
                stack2.add(stack1.peek());
                stack1.pop();
            }
            return stack2.peek();
        }
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