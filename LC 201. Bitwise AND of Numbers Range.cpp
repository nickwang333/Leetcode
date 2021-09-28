class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long ret = left;
        if(left==0 || right/left>1){return 0;}
        for(long i=left; i<=right; i++){
            ret &= i;
        }
        return ret;
    }
};
