class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int tmp = 0, tmp2 = 0;
        for(int i=0; i<target.size(); i++){
            if(target[i] == '1'){
                tmp++;
            }
            if(s[i] == '0'){
                tmp2++;
            }
        }
        if(tmp == 0 && tmp2 == 0){
            return false;
        }
        if(tmp2 == target.size() && tmp != 0){
            return false;
        }
        if(tmp == 0 && tmp2 != target.size()){
            return false;
        }
        return true;
    }
};
