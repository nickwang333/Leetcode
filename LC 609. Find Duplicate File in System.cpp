class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> ret;
        for(string i:paths){
            string path = "", name = "", context = "", tmp = "";
            for(char j:i){
                if(j == ' '){
                    if(path == ""){
                        path = tmp;
                    }
                    tmp = "";
                }
                else if(j == '('){
                    name = tmp;
                    tmp = "";
                }
                else if(j == ')'){
                    context = tmp;
                    tmp = "";
                    string tmp2 = path + "/" + name;
                    m[context].push_back(tmp2);
                }
                else{
                    tmp += j;
                }
            }
        }
        for(auto i:m){
            if(i.second.size() > 1){
                ret.push_back(i.second);
            }
        }
        return ret;
    }
};
