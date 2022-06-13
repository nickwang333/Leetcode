class UndergroundSystem {
public:
    map<int, int> m2; // Used to track check in time
    map<int, string> m3; // Used to track check in station
    map<string, int> m4; // Used to track in out counter
    map<string, int> m5; // Used to track in out time
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m2[id] = t;
        m3[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        int tmp = t-m2[id];
        string tmps = m3[id]+"afascac"+stationName;
        m4[tmps]++;
        m5[tmps] += (t-m2[id]);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string tmps = startStation+"afascac"+endStation;
        return double(m5[tmps])/double(m4[tmps]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
