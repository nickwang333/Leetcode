class MinStack {
public:
    stack<int> s;
    map<int,int> m;
    /** initialize your data structure here. */
    MinStack() {
        while(!s.empty()){
            s.pop();
        }
        m.clear();
    }
    
    void push(int x) {
        s.push(x);
        m[x]++;
    }
    
    void pop(){
        m[s.top()]--;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        for(auto it = m.begin(); it!=m.end(); it++){
            if(it->second != 0){
                return it->first;
            }
        }
        return -1;
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
