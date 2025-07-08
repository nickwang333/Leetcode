class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size(), tmp = 0, pointer = 0, total = 0;
        for(char i:abbr){
            if(isdigit(i)){
                if(tmp == 0 && i-'0' == 0){
                    return false;
                }
                tmp *= 10;
                tmp += (i-'0');
            }
            else{
                if(tmp != 0){
                    pointer += tmp;
                    total += tmp;
                    tmp = 0;
                }
                if(tmp >= abbr.size() || word[pointer] != i){
                    return false;
                }
                total++;
                pointer++;
            }
        }
        total += tmp;
        return total == n;
    }
};
