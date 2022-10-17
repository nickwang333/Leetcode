class Solution {
public:
    int minSteps(string s, string t) {
        int ret = 0;
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
        }
        for(int i:v){
            if(i>0){
                ret += i;
            }
        }
        return ret;
    }
};
