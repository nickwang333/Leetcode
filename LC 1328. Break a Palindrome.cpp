class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ret = palindrome;
        if(n==1){
            return "";
        }
        for(int i=0; i<n/2; i++){
            if(ret[i] != 'a'){
                ret[i] = 'a';
                return ret;
            }
        }
        if(ret == palindrome){
            ret[n-1] = 'b';
            return ret;
        }
        return ret;
    }
};
