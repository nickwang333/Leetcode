class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int> v(s.size());
        for(int i=0; i<s.size(); i++){
            v[i] = s[i]-'a';
        }
        int tsum = 0;
        for(int i=s.size()-1; i>=0; i--){
            int sv = shifts[i]%26;
            tsum += sv;
            tsum %= 26;
            v[i] += tsum;
            v[i] %= 26;
        }
        string ret;
        for(int i:v){
            ret += (i+'a');
        }
        return ret;
    }
};
