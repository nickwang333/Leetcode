class MyQueue {
public:
    int fp;
    vector<int> v;
    MyQueue() {
        vector<int> n(0);
        v = n;
        fp = 0;
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
        fp++;
        return v[fp-1];
    }
    
    int peek() {
        return v[fp];
    }
    
    bool empty() {
        return fp==v.size();
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
