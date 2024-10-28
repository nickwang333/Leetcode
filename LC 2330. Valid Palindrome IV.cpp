class Solution {
public:
    bool makePalindrome(string s) {
        int diff = 0, n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                diff++;
            }
        }
        return diff <= 2;
    }
};
