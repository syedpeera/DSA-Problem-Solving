class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(stack1.empty()){
            stack1.push(x);
        }
        else{
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            
            stack1.push(x);
            
            while(!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
    }
    
    int pop() {
        int element = stack1.top();
        stack1.pop();
        return element;
    }
    
    int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */