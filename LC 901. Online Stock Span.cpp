class StockSpanner {
    stack<int> s, s2;
    int counter;
public:
    StockSpanner() {
        counter = 0;
    }
    
    int next(int price) {
        int ret = 0;
        if(s.empty()){
            s.push(price);
            s2.push(counter);
            ret = 1;
        }
        else{
            while(!s.empty() && s.top()<=price){
                s.pop();
                s2.pop();
            }
            if(s.empty()){
                ret = counter+1;
            }
            else{
                ret = counter - s2.top();
            }
            s.push(price);
            s2.push(counter);
        }
        counter++;
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
