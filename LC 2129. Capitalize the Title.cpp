class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> v;
        string tmp;
        for(char i:title){
            if(i==' '){
                v.push_back(tmp);
                tmp = "";
            }
            else{
                tmp += i;
            }
        }
        string ret;
        v.push_back(tmp);
        for(string i:v){
            if(i.size()<3){
                for(char j:i){
                    ret += tolower(j);
                }
            }
            else{
                for(int j=0; j<i.size(); j++){
                    if(j==0){
                        ret += toupper(i[j]);
                    }
                    else{
                        ret += tolower(i[j]);
                    }
                }
            }
            ret += ' ';
        }
        return ret.substr(0, ret.size()-1);
    }
};
