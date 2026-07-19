class MinStack {
public:
    stack<int> stacker;
    stack<int> min;

    MinStack() {
    
    }
    
    void push(int value) {
        stacker.push(value);
        if(!min.empty() && value > min.top()){
            min.push(min.top());
        }else{
            min.push(value);
        }
    }
    
    void pop() {
        stacker.pop();
        min.pop();
    }
    
    int top() {
        return stacker.top();
        
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your Minstacker object will be instantiated and called as such:
 * Minstacker* obj = new Minstacker();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->stacker();
 * int param_4 = obj->getMin();
 */