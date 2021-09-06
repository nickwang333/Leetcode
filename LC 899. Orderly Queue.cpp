class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(), s.end());
            return s;
        }
        string ret = s, sc;
        for(int i=0; i<s.size(); i++){
            sc = s.substr(1);
            sc += s[0];
            ret = min(ret, sc);
            s = sc;
        }
        return ret;
    }
};
