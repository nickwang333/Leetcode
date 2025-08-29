class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ret = "";
        if(s.size() == 1){
            return s;
        }
        for(int i=0; i<n-1; i++){
            int len = 0;
            for(int j=1; j<n; j++){
                if(i-j < 0 || i+j >= n || s[i-j] != s[i+j]){
                    break;
                }
                else{
                    len++;
                }
            }
            if(len*2+1 > ret.size()){
                ret = s.substr(i-len, len*2+1);
            }
            if(s[i] == s[i+1]){
                len = 2;
                for(int j=1; j<n; j++){
                    if(i-j < 0 || i+j+1 >= n || s[i-j] != s[i+j+1]){
                        break;
                    }
                    else{
                        len += 2;
                    }
                }
                if(len > ret.size()){
                    ret = s.substr(i+1-len/2, len);
                }
            }
        }
        return ret;
    }
};
