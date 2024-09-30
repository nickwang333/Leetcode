class CustomStack {
    int sz;
    stack<int> s;
public:
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(s.size() < sz){
            s.push(x);
        }
    }
    
    int pop() {
        if(s.size() == 0){
            return -1;
        }
        else{
            int tmp = s.top();
            s.pop();
            return tmp;
        }
    }
    
    void increment(int k, int val) {
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        for(int i=0; i<k; i++){
            if(s2.empty()){
                break;
            }
            s.push(s2.top() + val);
            s2.pop();
        }
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
