class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> m;
        for(string i:strs){
            vector<int> v(26, 0);
            for(char j:i){
                v[j-'a']++;
            }
            string key = "";
            for(int j:v){
                key += to_string(j);
                key += ";";
            }
            m[key].push_back(i);
        }
        for(auto i:m){
            ret.push_back(i.second);
        }
        return ret;
    }
};
