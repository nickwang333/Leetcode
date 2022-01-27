class Solution {
public:
    string originalDigits(string s) {
        map<char,int> m;
        for(char i:s){
            m[i]++;
        }
        string ret = "";
        for(int i=0; i<m['z']; i++){
            ret += '0';
        }
        for(int i=0; i<(m['o']-m['z']-m['w']-m['u']); i++){
            ret += '1';
        }
        for(int i=0; i<m['w']; i++){
            ret += '2';
        }
        for(int i=0; i<(m['t']-m['w']-m['g']); i++){
            ret += '3';
        }
        for(int i=0; i<m['u']; i++){
            ret += '4';
        }
        for(int i=0; i<(m['f']-m['u']); i++){
            ret += '5';
        }
        for(int i=0; i<m['x']; i++){
            ret += '6';
        }
        for(int i=0; i<(m['s']-m['x']); i++){
            ret += '7';
        }
        for(int i=0; i<m['g']; i++){
            ret += '8';
        }
        for(int i=0; i<(m['i']+m['u']-m['f']-m['x']-m['g']); i++){
            ret += '9';
        }
        return ret;
    }
};
