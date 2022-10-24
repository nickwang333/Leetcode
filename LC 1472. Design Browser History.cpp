class BrowserHistory {
    unordered_map<int, string> m;
    int id = 0, maxid = 0;
public:
    BrowserHistory(string homepage) {
        m[id] = homepage;
        id++;
        maxid = id;
    }
    
    void visit(string url) {
        m[id] = url;
        id++;
        maxid = id;
    }
    
    string back(int steps) {
        if(steps < id){
            id -= steps;
            return m[id-1];
        }
        else{
            id = 1;
            return m[id-1];
        }
    }
    
    string forward(int steps) {
        if(steps+id <= maxid){
            id+=steps;
            return m[id-1];
        }
        else{
            id = maxid;
            return m[maxid-1];
        }
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
