class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int n = s.size(), ret = 0;
        map<char, int> m;
        for(char i:s){
            m[i]++;
        }
        if(n<count){
            return 0;
        }
        for(int i=1; i<=m.size(); i++){
            int cnt[26] = {}, len = i*count, unique = 0, ct = 0;
            for(int j=0; j<n; j++){
                cnt[s[j]-'a']++;
                if(cnt[s[j]-'a']==count){
                    ct++;
                }
                if(j>=len){
                    cnt[s[j-len]-'a']--;
                }
                if(j>=len && (cnt[s[j-len]-'a']+1 == count)){
                    ct--;
                }
                ret += ct == i;
            }
        }
        return ret;
    }
};
