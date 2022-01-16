class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ret = 0;
        for(int i=0; i<maxDoubles; i++){
            if(target==1){
                return ret;
            }
            if(target%2==0){
                target/=2;
            }
            else{
                target--;
                target/=2;
                ret++;
            }
            ret++;
        }
        return ret+target-1;
    }
};
