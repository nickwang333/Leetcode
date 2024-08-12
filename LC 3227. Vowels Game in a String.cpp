class Solution {
public:
    bool doesAliceWin(string s) {
        int total = 0;
        for(char i:s){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                total++;
            }
        }
        if(total == 0){
            return false;
        }
        return true;
    }
};
