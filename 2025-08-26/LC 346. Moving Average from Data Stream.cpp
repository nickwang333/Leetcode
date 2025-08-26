class MovingAverage {
    int total = 0, n = 0;
    queue<int> q;
public:
    MovingAverage(int size) {
        n = size;
    }
    
    double next(int val) {
        q.push(val);
        total += val;
        if(q.size() > n){
            total -= q.front();
            q.pop();
        }
        double ret = double(total) / double(q.size());
        return ret;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
