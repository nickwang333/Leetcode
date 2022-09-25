class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ret;
        map<int, string> m;
        for(int i=0; i<names.size(); i++){
            m[heights[i]] = names[i];
        }
        for(auto it=m.rbegin(); it!=m.rend(); it++){
            ret.push_back(it->second);
        }
        return ret;
    }
};
