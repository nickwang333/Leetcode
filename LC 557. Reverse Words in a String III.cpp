class Solution {
public:
    string reverseWords(string s) {
        string ret = "", tmp = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ' && tmp != ""){
                reverse(tmp.begin(), tmp.end());
                ret += tmp;
                ret += ' ';
                tmp = "";
            }
            else{
                tmp += s[i];
            }
        }
        reverse(tmp.begin(), tmp.end());
        ret += tmp;
        return ret;
    }
};
