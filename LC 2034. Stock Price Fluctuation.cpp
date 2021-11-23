class StockPrice {
public:
    int curr, time;
    map<int, int> m, m2;
    StockPrice() {
        time = 0;
    }
    
    void update(int timestamp, int price) {
        if(timestamp >= time){
            time = timestamp;
            curr = price;
        }
        m[m2[timestamp]]--;
        if(m[m2[timestamp]] == 0){
            m.erase(m2[timestamp]);
        }
        m[price]++;
        m2[timestamp] = price;
    }
    
    int current() {
        return curr;
    }
    
    int maximum() {
        auto it = m.rbegin();
        return it->first;
    }
    
    int minimum() {
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->first != 0 && it->second != 0){
                return it->first;
            }
        }
        return 0;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
