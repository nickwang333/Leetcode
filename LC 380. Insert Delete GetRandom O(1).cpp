class RandomizedSet {
public:
    int n;
    vector<int> v;
    unordered_map<int, int> m;
    
    RandomizedSet() {
        n = 0;
    }
    
    bool insert(int val) {
        auto it = m.find(val);
        if(it == m.end() || it->second == -1){
            m[val] = n;
            n++;
            if(v.size()<n){
                v.push_back(val);
            }
            else{
                v[n-1] = val;
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if(it == m.end() || it->second == -1){
            return false;
        }
        else{
            if(m[val] == n-1){
                m[val] = -1;
                n--;
            }
            else{
                int tmp = v[n-1];
                m[tmp] = m[val];
                m[val] = -1;
                v[m[tmp]] = tmp;
                n--;
            }
        }
        return true;
    }
    
    int getRandom() {
        int tmp = rand() % n;
        return v[tmp];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
