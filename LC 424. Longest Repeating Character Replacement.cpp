class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), prev = 0, ret = 0;
        map<char, int> m;
        for(int i=0; i<n; i++){
            m[s[i]]++;
            while(prev<i && (i-prev-k+1)>m[s[prev]]){
                m[s[prev]]--;
                prev++;
            }
            ret = max(ret, i-prev+1);
            ret = max(ret, m[s[prev]]+k);
        }
        if(ret > n){
            ret = n;
        }
        return ret;
    }
};
