class Solution {
public:
    int minimizedStringLength(string s) {
        vector<int> v(26,0);
        int ret = 0;
        for(char i:s){
            v[i-'a'] = 1;
        }
        for(int i:v){
            ret += i;
        }
        return ret;
    }
};
