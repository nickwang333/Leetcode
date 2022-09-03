class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0; i<32; i++){
            int tmp = n >> 1;
            if(n == 0){
                ret = ret << 1;
            }
            else if(tmp << 1 != n){
                ret = ret << 1;
                ret++;
            }
            else{
                ret = ret << 1;
            }
            n = tmp;
        }
        return ret;
    }
};
