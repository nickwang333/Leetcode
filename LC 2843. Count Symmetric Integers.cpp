class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ret = 0;
        for(int i=low; i<=high; i++){
            string s1 = to_string(i);
            if(s1.size()%2 == 0){
                int tsum1 = 0, tsum2 = 0;
                for(int j=0; j<s1.size()/2; j++){
                    tsum1 += (s1[j]-'0');
                }
                for(int j=s1.size()/2; j<s1.size(); j++){
                    tsum2 += (s1[j]-'0');
                }
                if(tsum1 == tsum2){
                    ret++;
                }
            }
        }
        return ret;
    }
};
