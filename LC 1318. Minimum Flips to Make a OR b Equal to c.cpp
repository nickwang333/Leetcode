class Solution {
public:
    int minFlips(int a, int b, int c) {
        int tmpa = a, tmpb = b, tmpc = c, ret = 0;
        vector<int> va(32, 0), vb(32, 0), vc(32, 0);
        for(int i=31; i>=0; i--){
            if(tmpa >= pow(2,i)){
                tmpa -= pow(2,i);
                va[i] = 1;
            }
            if(tmpb >= pow(2,i)){
                tmpb -= pow(2,i);
                vb[i] = 1;
            }
            if(tmpc >= pow(2,i)){
                tmpc -= pow(2,i);
                vc[i] = 1;
            }
        }
        for(int i=31; i>=0; i--){
            
            if(vc[i] == 0){
                ret += va[i];
                ret += vb[i];
            }
            else{
                if(va[i] == 0 && vb[i] == 0){
                    ret++;
                }
            }
        }
        return ret;
    }
};
