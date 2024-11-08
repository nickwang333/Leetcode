class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int total = 0;
        unordered_map<string, int> m;
        for(string i:bannedWords){
            m[i] = 1;
        }
        for(string i:message){
            if(m[i] == 1){
                total++;
            }
        }
        return total >= 2;
    }
};
