class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        for(string i:words){
            if(i.size() >= pref.size()){
                if(pref == i.substr(0, pref.size())){
                    ret++;
                }
            }
        }
        return ret;
    }
};
