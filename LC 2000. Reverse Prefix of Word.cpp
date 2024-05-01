class Solution {
public:
    string reversePrefix(string word, char ch) {
        int sz = word.size(), flag = 0;
        string ret = "";
        for(char i:word){
            if(i == ch){
                if(flag == 0){
                    ret += i;
                    reverse(ret.begin(), ret.end());
                    flag = 1;
                }
                else{
                    ret += i;
                }
            }
            else{
                ret += i;
            }
        }
        return ret;
    }
};
