class MinStack {
public:
    stack<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            pair<int,int>p;
            p.first=val;
            p.second=val;
            s.push(p);
        }
        else{
            pair<int,int>p;
            p.first=val;
            p.second= min(val, s.top().second);
            s.push(p);
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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