class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n != 0){
            int tmp = n >> 1;
            if(tmp << 1 != n){
                ret++;
            }
            n = tmp;
        }
        return ret;
    }
};
