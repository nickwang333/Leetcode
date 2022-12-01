class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int ret = 0, prev = 0;
        unordered_map<char,int> m;
        for(int i=0; i<26; i++){
            m[keyboard[i]] = i;
        }
        for(char i:word){
            ret += abs(m[i]-prev);
            prev = m[i];
        }
        return ret;
    }
};
