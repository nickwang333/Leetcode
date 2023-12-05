class Solution {
public:
    int numberOfMatches(int n) {
        int ret = 0;
        while(n > 1){
            if(n%2 == 0){
                ret += n/2;
                n /= 2;
            }
            else{
                ret += (n-1)/2;
                n = (n-1)/ 2 + 1;
            }
        }
        return ret;
    }
};
