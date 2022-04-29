class Logger {
public:
    map<string, int> m;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = m.find(message);
        if(it == m.end()){
            m[message] = -10;
        }
        if(m[message]+10<=timestamp){
            m[message] = timestamp;
            return true;
        }
        else{
            cout << m[message];
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
