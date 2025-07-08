class Solution {
    
public:
    bool isPalindrome(string& s, int i){
        int n = s.size()-1, pointer = 0;
        while(n > pointer){
            if(n == i){
                n--;
            }
            if(pointer == i){
                pointer++;
            }
            if(s[pointer] != s[n]){
                return false;
            }
            n--;
            pointer++;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                return isPalindrome(s, i) || isPalindrome(s, n-i-1);
            }
        }
        return true;
    }
};
