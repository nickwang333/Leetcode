class Solution {
public:
    bool isStrobogrammatic(string num) {
        string tmp;
        for(char i:num){
            if(i == '8' || i == '0' || i == '1'){
                tmp += i;
            }
            else if(i == '6'){
                tmp += '9';
            }
            else if(i == '9'){
                tmp += '6';
            }
            else{
                return false;
            }
        }
        reverse(tmp.begin(), tmp.end());
        return tmp == num;
    }
};
