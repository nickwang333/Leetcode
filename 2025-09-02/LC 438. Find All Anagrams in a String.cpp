class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int n = s.size(), m = p.size();
        if(m > n){
            return ret;
        }
        vector<int> v1(26, 0), v2(26, 0);
        for(int i=0; i<m; i++){
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
        }
        int match = 0;
        for(int i=0; i<26; i++){
            if(v1[i] == v2[i]){
                match++;
            }
        }
        if(match == 26){
            ret.push_back(0);
        }
        for(int i=m; i<n; i++){
            if(v1[s[i]-'a'] == v2[s[i]-'a']){
                match--;
            }
            v1[s[i]-'a']++;
            if(v1[s[i]-'a'] == v2[s[i]-'a']){
                match++;
            }
            if(v1[s[i-m]-'a'] == v2[s[i-m]-'a']){
                match--;
            }
            v1[s[i-m]-'a']--;
            if(v1[s[i-m]-'a'] == v2[s[i-m]-'a']){
                match++;
            }
            if(match == 26){
                ret.push_back(i-m+1);
            }
        }
        return ret;
    }
};
