class Solution {
public:
    int minChanges(int n, int k) {
        if((n|k) > n){
            return -1;
        }
        int tmp = n-k, ret = 0;
        while(tmp > 0){
            ret += tmp%2;
            tmp /= 2;
        }
        return ret;
    }
};
