class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(n%(i+1) == 0){
                int flag = 0;
                for(int j=0; j<n; j+=(i+1)){
                    if(s.substr(j, i+1) != s.substr(0, i+1)){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    return true;x
                }
            }
        }
        return false;
    }
};
