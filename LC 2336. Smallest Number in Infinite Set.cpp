class SmallestInfiniteSet {
    unordered_map<int, int> m;
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        for(int i = 1; i<2000; i++){
            if(m[i] == 0){
                m[i] = 1;
                return i;
            }
        }
        return 2000;
    }
    
    void addBack(int num) {
        m[num] = 0;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
