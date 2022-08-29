class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int n = s.size(), prev = 0, ret = 0;
        for(int i=0; i<n; i++){
            m[s[i]]++;
            while(prev<=i && m[s[i]]>1){
                m[s[prev]]--;
                prev++;
            }
            ret = max(ret, i-prev+1);
        }
        return ret;
    }
};
