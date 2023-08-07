class Solution {
public:
    string finalString(string s) {
        string tmp;
        for(char i:s){
            if(i == 'i'){
                reverse(tmp.begin(), tmp.end());
            }
            else{
                tmp += i;
            }
        }
        return tmp;
    }
};
