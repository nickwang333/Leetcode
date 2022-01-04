class Solution {
public:
    int bitwiseComplement(int n) {
        int tmp = 1;
        if(n==0){
            return 1;
        }
        while(tmp<=n){
            tmp*=2;
        }
        return tmp-n-1;
    }
};
