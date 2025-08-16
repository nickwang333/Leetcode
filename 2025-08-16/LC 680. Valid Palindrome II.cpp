class Solution {
public:
    bool isValid(string& s, int index){
        int n = s.size();
        int index1 = 0;
        int index2 = n-1;
        for(int i=0; i<n/2; i++){
            if(index1 == index){
                index1++;
            }
            if(index2 == index){
                index2--;
            }
            if(s[index1] != s[index2]){
                return false;
            }
            index1++;
            index2--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            if(s[i] != s[n-i-1]){
                return isValid(s, i) || isValid(s, n-1-i);
            }
        }
        return true;
    }
};
