class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ret = "", tmp = "";
        vector<string> v;
        for(char i:sentence){
            if(i == ' '){
                for(string j:dictionary){
                    if(j.size() <= tmp.size() && tmp.substr(0, j.size()) == j){
                        if(j.size() < tmp.size()){
                            tmp = j;
                        }
                    }
                }
                ret += tmp;
                ret += " ";
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        for(string j:dictionary){
            if(j.size() <= tmp.size() && tmp.substr(0, j.size()) == j){
                if(j.size() < tmp.size()){
                    tmp = j;
                }
            }
        }
        ret += tmp;
        return ret;
    }
};
