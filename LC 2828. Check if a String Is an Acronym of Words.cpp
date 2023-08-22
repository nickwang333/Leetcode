class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string tmp;
        for(string i:words){
            tmp += i[0];
        }
        return tmp == s;
    }
};
