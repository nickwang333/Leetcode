class Solution {
public:
    int maxOperations(string s) {
        string s2;
        if(s[0] == '1'){
            s2 += s[0];
        }
        for(int i=1; i<s.size(); i++){
            if(s[i] == '1'){
                s2 += s[i];
            }
            else{
                if(s[i-1] == '1'){
                    s2 += s[i];
                }
            }
        }
        int n = s2.size(), ret = 0, total = 0;
        for(int i=0; i<n; i++){
            if(s2[i] == '0'){
                ret += total;
            }
            else{
                total++;
            }
        }
        return ret;
    }
};
