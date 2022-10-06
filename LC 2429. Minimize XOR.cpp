class Solution {
public:
    int minimizeXor(int num1, int num2) {
       int tmp1 = num2, bits = 0, ret = 0;
        vector<int> v(32,0);
        vector<bool> v2(32,false);
        for(int i=0; i<31; i++){
            int tmp2 = pow(2,i);
            int tmp3 = num1&tmp2;
            if(tmp3 > 0){
                
                v[i] = 1;
            }
        }
        while(tmp1 > 0){
            int tmp2 = tmp1 >> 1;
            if(tmp2*2 != tmp1){
                bits++;
            }
            tmp1 = tmp2;
        }
        for(int i=30; i>=0; i--){
            if(v[i] == 1 && bits > 0){
                v[i] = 0;
                bits--;
                v2[i] = true;
                ret += pow(2,i);
            }
        }
        for(int i=0; i<31; i++){
            if(bits > 0 && !v2[i] && v[i] == 0){
                bits--;
                ret += pow(2,i);
            }
        }
        return ret;
    }
};
