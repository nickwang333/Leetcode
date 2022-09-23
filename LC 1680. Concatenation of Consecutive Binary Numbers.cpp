class Solution {
public:
    int count(int n){
        int ret = 0, tmp = n;
        while(tmp > 0){
            ret++;
            tmp >>= 1;
        }
        return ret;
    }
    
    int concatenatedBinary(int n) {
        int ret = 0, mod = 1000000007;
        for(int i=1; i<=n; i++){
            long tmp2 = ret;
            int tmp = count(i);
            tmp2 = tmp2*int(pow(2,tmp))%mod;
            ret = (tmp2+i)%mod;
        }
        return ret;
    }
};
