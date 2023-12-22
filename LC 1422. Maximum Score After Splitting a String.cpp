class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), c1 = 0, c0 = 0, ret = 0;
        for(auto i:s){
            if(i == '1'){
                c1++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(s[i] == '0'){
                c0++;
            }
            else{
                c1--;
            }
            ret = max(ret, c0+c1);
        }
        return ret;
    }
};
