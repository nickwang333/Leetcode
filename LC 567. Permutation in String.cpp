class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26,0), tmp(26,0);
        int total = 0;
        if(s2.size() < s1.size()){
            return false;
        }
        for(int i=0; i<s1.size(); i++){
            tmp[s2[i]-'a']++;
            v[s1[i]-'a']++;
        }
        for(int j=0; j<26; j++){
            if(tmp[j] == v[j]){
                total++;
            }
        }
            if(total == 26){
                return true;
            }
        for(int i=s1.size(); i<s2.size(); i++){
            total = 0;
            tmp[s2[i]-'a']++;
            tmp[s2[i-s1.size()]-'a']--;
            for(int j=0; j<26; j++){
                if(tmp[j] == v[j]){
                    total++;
                }
            }
            if(total == 26){
                return true;
            }
        }
        return false;
    }
};
