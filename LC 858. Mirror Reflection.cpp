class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(p%2 == 0 && q%2 == 0){
            p/=2;
            q/=2;
        }
        p %= 2;
        q %= 2;
        if(p == q){
            return 1;
        }
        else if(p == 1 && q == 0){
            return 0;
        }
        else{
            return 2;
        }
    }
};
