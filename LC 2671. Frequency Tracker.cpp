class FrequencyTracker {
    unordered_map<int, int> m1, m2;
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        m1[number]++;
        m2[m1[number]-1]--;
        m2[m1[number]]++;
    }
    
    void deleteOne(int number) {
        if(m1[number] > 0){
            m1[number]--;
            m2[m1[number]+1]--;
            m2[m1[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return m2[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
