class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ret;
        for(string i:words){
            string tmp = "";
            for(char j:i){
                if(j == separator){
                    if(tmp != ""){
                        ret.push_back(tmp);
                    }
                    tmp = "";
                }
                else{
                    tmp += j;
                }
            }
            if(tmp != ""){
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
