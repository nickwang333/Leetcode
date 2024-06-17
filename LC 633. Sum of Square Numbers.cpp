class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long, int> m;
        for(long i=0; i<pow(2,16); i++){
            m[i * i] = 1;
        }
        for(auto it:m){
            long tmp = c - it.first;
            if(m.find(tmp) != m.end()){
                return true;
            }
        }
        return false;
    }
};
