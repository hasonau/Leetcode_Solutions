class MinStack {
private :
    stack<pair<int,int>>s;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()) s.emplace(val,val);
        else{
            auto p= s.top();
            int currentMin = p.second;
            currentMin= min(val,currentMin);
            s.emplace(val,currentMin);
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        auto p= s.top();
        return p.first;
    }
    
    int getMin() {
        auto p= s.top();
        return p.second;
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