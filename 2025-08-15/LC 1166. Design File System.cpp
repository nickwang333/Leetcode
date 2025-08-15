class FileSystem {
    unordered_map<string, int> m;
    unordered_map<string, int> val;
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if(path == "" || path == "/" || path[0] != '/'){
            return false;
        }
        int n = path.size(), len = n;
        for(int i=n-1; i>=0; i--){
            if(path[i] == '/'){
                len--;
            }
            else{
                break;
            }
        }
        path = path.substr(0, len);
        string curr = "/";
        for(int i=1; i<len; i++){
            if(path[i] == '/'){
                if(m[curr] != 1){
                    return false;
                }
                m[curr] = 1;
            }
            curr += path[i];
        }
        if(val.find(path) != val.end()){
            return false;
        }
        m[path] = 1;
        val[path] = value;
        return true;
    }
    
    int get(string path) {
        if(val.find(path) == val.end()){
            return -1;
        }
        return val[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
