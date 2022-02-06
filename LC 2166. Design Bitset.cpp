class Bitset {
public:
    vector<int> v;
    bool reverse;
    int total, ones;
    Bitset(int size) {
        vector<int> tmp(size,0);
        v = tmp;
        reverse = false;
        ones = 0;
        total = size;
    }
    
    void fix(int idx) {
        if(!reverse){
            if(v[idx] == 0){
                ones++;
                v[idx] = 1;
            }
        }
        else{
            if(v[idx] == 1){
                ones++;
                v[idx] = 0;
            }
        }
    }
    
    void unfix(int idx) {
        if(!reverse){
            if(v[idx] == 1){
                ones--;
                v[idx] = 0;
            }
        }   
        else{
            if(v[idx] == 0){
                ones--;
                v[idx] = 1;
            }
        }
    }
    
    void flip() {
        ones = total - ones;
        if(reverse){
            reverse = false;
        }
        else{
            reverse = true;
        }
    }
    
    bool all() {
        return ones==total;
    }
    
    bool one() {
        return ones>=1;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string ret = "";
        if(reverse){
            for(int i:v){
                if(i==0){
                    ret += '1';
                }
                else{
                    ret +='0';
                }
            }
        }
        else{
            for(int i:v){
                if(i==0){
                    ret += '0';
                }
                else{
                    ret +='1';
                }
            }
        }
        return ret;

    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
