class SeatManager {
    priority_queue<int> s;
    int sz = -1, curr = 0;
public:
    SeatManager(int n) {
        for(int i=1; i<=n; i++){
            s.push(-i);
        }
    }
    
    int reserve() {
        int tmp = s.top();
        s.pop();
        return -tmp;
    }
    
    void unreserve(int seatNumber) {
        s.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
