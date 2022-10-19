class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> ret;
        for(string i:words){
            m[i]++;
        }
        map<int, vector<string>> m2;
        for(auto i:m){
            m2[i.second].push_back(i.first);
        }
        for(auto it = m2.rbegin(); it != m2.rend(); it++){
            sort(it->second.begin(), it->second.end());
            for(string j:it->second){
                ret.push_back(j);
                k--;
                if(k == 0){
                    return ret;
                }
            }
        }
        return ret;
    }
};
