class Solution {
public:
    int totalMoney(int n) {
        int ret = 0;
        for(int i=1; i<=n; i++){
            ret += i%7;
            if(i%7 == 0){
                ret += 7;
            }
            ret += (i-1)/7;
        }
        return ret;
    }
};
