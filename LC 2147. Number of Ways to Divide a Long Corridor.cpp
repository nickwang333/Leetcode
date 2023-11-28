class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007, counter = 0, tmp = 0;
        long ret = 1;
        for(char i:corridor){
            if(i == 'P'){
                if(counter != 0 && counter % 2 == 0){
                    tmp++;
                }
            }
            else{
                counter++;
                if(counter % 2 == 1){
                    ret *= (tmp+1);
                    ret %= mod;
                    tmp = 0;
                }
            }
        }
        if(counter % 2 == 1 || counter == 0){
            return 0;
        }
        return ret;
    }
};
