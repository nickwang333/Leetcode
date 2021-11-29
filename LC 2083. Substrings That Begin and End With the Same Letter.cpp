class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ret = 0;
        map<char, long long> m;
        for(char i:s){
            m[i]++;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            ret += (long(it->second)*(long(it->second)+1)/2);
        }
        return ret;
    }
};
