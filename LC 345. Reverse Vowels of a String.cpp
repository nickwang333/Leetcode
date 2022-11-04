class Solution {
public:
    string reverseVowels(string s) {
        string s2, ret;
        int j = 0;
        for(char i:s){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
            i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U' ){
                s2 += i;
            }
        }
        reverse(s2.begin(), s2.end());
        for(char i:s){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
            i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U' ){
                ret += s2[j];
                j++;
            }
            else{
                ret += i;
            }
        }
        return ret;
    }
};
