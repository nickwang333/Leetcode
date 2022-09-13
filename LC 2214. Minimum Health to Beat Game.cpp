class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long ret = 1, prev = 0;
        for(int i:damage){
            ret += i;
            if(prev < i){
                prev = i;
            }
        }
        if(prev > armor){
            ret -= armor;
            if(ret < 0){
                ret = 1;
            }
        }
        else{
            ret -= prev;
        }
        return ret;
    }
};
