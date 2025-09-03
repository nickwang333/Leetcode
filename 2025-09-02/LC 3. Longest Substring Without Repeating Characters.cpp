class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ret = 1;
        if(n == 0){
            return 0;
        }
        unordered_map<char, int> v;
        int p0 = 0;
        for(int i=0; i<n; i++){
            v[s[i]]++;
            while(p0<i && v[s[i]] != 1){
                v[s[p0]]--;
                p0++;
            }
            ret = max(ret, i-p0+1);
        }
        return ret;
    }
};
