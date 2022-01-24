class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int counter = 0, fp = 0, sp = 0, n = s.size(), ret = 0;
        unordered_map<char, int> v;
        if(k==0){
            return 0;
        }
        while(fp<n){
            v[s[fp]]++;
            if(v[s[fp]] == 1){
                counter++;
                while(counter > k){
                    v[s[sp]]--;
                    if(v[s[sp]] == 0){
                        counter--;
                    }
                    sp++;
                }
            }
            ret = max(ret, fp-sp+1);
            fp++;
        }
        return ret;
    }
};
