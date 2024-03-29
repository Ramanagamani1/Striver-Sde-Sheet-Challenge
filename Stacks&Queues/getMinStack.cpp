class MinStack {
    stack<long long> s;
    long mini ;
public:
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long value = val;
        if(s.empty()) {
             s.push(value);
             mini = value;
        }
        else {

            if(value<mini) {

                s.push(2*value*1L - mini);
                mini = value;
            } else {
                s.push(value);
            }
        }
    }
    
    void pop() {
        
        if(s.empty())  return;

        long long val = s.top();
        s.pop();
 
        if(val<=mini) {
            mini = 2*mini - val;
        }

    }
    
    int top() {
        if(s.empty())
           return -1;

        long long val = s.top();

        if(val<mini) {
           return mini;
        }
        else {
            return val;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */