class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> v1, ret;
        map<string, string> m;
        for(string i:logs){
            int j = i.size();
            if((i[j-1]-'0') >= 0 && (i[j-1]-'0') < 10){
                v1.push_back(i);
            }
            else{
                string tmp = "", tmp2 = "";
                for(int z=0; z<i.size(); z++){
                    if(i[z]==' '){
                        tmp2 = i.substr(z+1);
                        break;
                    }
                    tmp+=i[z];
                }
                tmp2 += "  ";
                tmp2 += tmp;
                m[tmp2] = i;
            }
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            ret.push_back(it->second);
        }
        for(string i:v1){
            ret.push_back(i);
        }
        return ret;
    }
};
