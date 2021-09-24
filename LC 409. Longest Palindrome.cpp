class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(char i:s){
            m[i]++;
        }
        int ret = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            ret += (it->second/2*2);
        }
        ret++;
        if(ret>s.size()){
            return s.size();
        }
        return ret;
    }
};
