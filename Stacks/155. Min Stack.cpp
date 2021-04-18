class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> s1; //to store normally
    
    stack<int> s2; //to store min - it has to keep account of pop operations 
    
    MinStack() {
        //constructor
    }
    
    void push(int x) {
        s1.push(x);
        
        if(s2.empty())
            s2.push(x);
        else s2.push(min(x, s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
