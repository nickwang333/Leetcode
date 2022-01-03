class Solution {
public:
    int knightDialer(int n) {
        vector<int> v(10, 1);
        int ret;
        long long tmp = 0;
        if(n==1){
            return 10;
        }
        for(int i=2; i<=n; i++){
            vector<long> tmpv(10,0);
            tmpv[0] = (v[4]+v[6])%(int(pow(10,9)+7));
            tmpv[1] = (v[8]+v[6])%(int(pow(10,9)+7));
            tmpv[2] = (v[7]+v[9])%(int(pow(10,9)+7));
            tmpv[3] = (v[4]+v[8])%(int(pow(10,9)+7));
            tmpv[4] = (long(v[3])+long(v[9])+long(v[0]))%(int(pow(10,9)+7));
            tmpv[6] = (long(v[1])+long(v[7])+long(v[0]))%(int(pow(10,9)+7));
            tmpv[7] = (v[2]+v[6])%(int(pow(10,9)+7));
            tmpv[8] = (v[1]+v[3])%(int(pow(10,9)+7));
            tmpv[9] = (v[2]+v[4])%(int(pow(10,9)+7));
            for(int i=0; i<10; i++){
                v[i] = tmpv[i];
            }
        }
        for(int i:v){
            tmp += i;
            tmp %= (int(pow(10,9)+7));
        }
        ret = tmp;
        return ret;
    }
};
