class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> v;
        map<string, vector<string>> m;
        for(int i=0; i<keyName.size(); i++){
            m[keyName[i]].push_back(keyTime[i]);
        }
        for(auto it = m.begin(); it != m.end(); it++){
            sort(it->second.begin(), it->second.end());
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second.size() < 3){
                continue;
            }
            for(int j=2; j<it->second.size(); j++){
                string tmp1 = "";
                tmp1 += it->second[j][0];
                tmp1 += it->second[j][1];
                tmp1 += it->second[j][3];
                tmp1 += it->second[j][4];
                string tmp2 = "";
                tmp2 += it->second[j-2][0];
                tmp2 += it->second[j-2][1];
                tmp2 += it->second[j-2][3];
                tmp2 += it->second[j-2][4];

                int diff = stoi(tmp1)-stoi(tmp2);
                
                if(diff <= 100){
                    v.push_back(it->first);
                    break;
                }
            }
            
        }
        
        return v;
    }
};
