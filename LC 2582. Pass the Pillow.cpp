class Solution {
public:
    int passThePillow(int n, int time) {
        int remain = time % (n-1);
        int div = time / (n-1);
        if(div % 2 == 1){
            return n-remain;
        }
        else{
            return 1+remain;
        }
    }
};
