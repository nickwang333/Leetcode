class Solution {
    
public:
    bool validPalindrome(string s) {
        int n = s.size(), diff = 0;
        string s1, s2;
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                for(int j=0; j<n; j++){
                    if(j != i){
                        s1 += s[j];
                    }
                    if(j != n-i-1){
                        s2 += s[j];
                    }
                }
                break;
            }
        }
        if(s1 == "" && s2 == ""){
            return true;
        }
        int flag1 = 0, flag2 = 0;
        for(int i=0; i<n/2; i++){
            if(s1[i] != s1[n-i-2]){
                flag1 = 1;
            }
            if(s2[i] != s2[n-i-2]){
                flag2 = 1;
            }
        }
        return flag1 == 0 || flag2 == 0;
    }
};
