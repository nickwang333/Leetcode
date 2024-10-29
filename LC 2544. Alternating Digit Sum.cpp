class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ret = 0;
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0){
                ret += (s[i]-'0');
            }
            else{
                ret -= (s[i]-'0');
            }
        }
        return ret;
    }
};
