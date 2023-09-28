class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ret;
        map<char, int> m;
        for(char i:s){
            m[i]++;
        }
        for(int i=0; i<m['1']-1; i++){
            ret += '1';
        }
        for(int i=0; i<m['0']; i++){
            ret += '0';
        }
        ret += '1';
        return ret;
    }
};
