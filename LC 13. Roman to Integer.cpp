class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int n = s.size(), ret = m[s[0]];
        for(int i=1; i<n; i++){
            ret += m[s[i]];
            if(m[s[i]] > m[s[i-1]]){
                ret -= (2*m[s[i-1]]);
            }
        }
        return ret;
    }
};
