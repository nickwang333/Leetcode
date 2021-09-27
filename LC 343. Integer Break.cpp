class Solution {
public:
    int integerBreak(int n) {
        if(n<7){
            return n/2*(n-n/2);
        }
        int tmp = n/3;
        if((n-tmp*3)==1){
            return pow(3,tmp-1)*4;
        }
        else if((n-tmp*3)==0){
            return pow(3,tmp);
        }
        else{
            return pow(3,tmp)*2;
        }
    }
};
