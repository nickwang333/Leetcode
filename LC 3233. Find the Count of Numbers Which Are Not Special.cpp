class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<int> prime(100002, 1);
        int ret = 0;
        prime[0] = 0;
        prime[1] = 0;
        for(int i=2; i<100002; i++){
            if(prime[i] == 1){
                for(int j=2; j<100002; j++){
                    if(i * j >= 100002){
                        break;
                    }
                    else{
                        prime[i*j] = 0;
                    }
                }
            }
        }
        ret = r-l+1;
        int a = ceil(sqrt(l));
        int b = floor(sqrt(r));
        for(int i=a; i<=b; i++){
            if(prime[i] == 1){
                ret--;
            }
        }
        return ret;
    }
};
