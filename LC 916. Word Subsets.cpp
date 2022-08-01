class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> m;
        vector<string> ret;
        for(int i=0; i<words2.size(); i++){
            unordered_map<char,int> tmp;
            for(char j:words2[i]){
                tmp[j]++;
            }
            for(auto it = tmp.begin(); it != tmp.end(); it++){
                m[it->first] = max(m[it->first], it->second);
            }
        }
        for(string i:words1){
            unordered_map<char,int> tmp;
            for(char j:i){
                tmp[j]++;
            }
            int flag = 0;
            for(auto it=m.begin(); it!=m.end(); it++){
                if(tmp[it->first] < it->second){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
