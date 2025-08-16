class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = abbr.size(), total = word.size(), sp = 0;
        string curr = "";
        for(int i=0; i<n; i++){
            if(isdigit(abbr[i])){
                if(abbr[i] == '0' && curr == ""){
                    return false;
                }
                curr += abbr[i];
            }
            else{
                if(curr != ""){
                    int len = stoi(curr);
                    sp += (len);
                    curr = "";
                }
                if(word[sp] == abbr[i]){
                    sp++;
                }
                else{
                    return false;
                }
            }
        }
        if(curr == ""){
            curr = "0";
        }
        return stoi(curr)+sp == total;
    }
};
