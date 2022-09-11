class Solution {
public:
    int partitionString(string s) {
        int ret = 1;
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++){
            if(v[s[i]-'a'] == 1){
                ret++;
                for(int j=0; j<26; j++){
                    v[j] = 0;
                }
                v[s[i]-'a'] = 1;
            }
            else{
                v[s[i]-'a']++;
            }
        }
        return ret;
    }
};
