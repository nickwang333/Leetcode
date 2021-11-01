class MovingAverage {
public:
    queue<int> q;
    double tsum, sp;
    MovingAverage(int size) {
        sp = size;
        tsum = 0;
    }
    
    double next(int val) {
        tsum += val;
        q.push(val);
        if(q.size()>sp){
            tsum -= q.front();
            q.pop();
        }
        return tsum/double(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
