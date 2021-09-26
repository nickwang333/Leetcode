class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> ret;
        int high = 0;
        if(s.size()<10){
            return ret;
        }
        for(int i=0; i<=s.size()-10; i++){
            string tmp = s.substr(i,10);
            m[tmp]++;
            high = max(high, m[tmp]);
        }
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second > 1){
                ret.push_back(it->first);
            }
        }
        return ret;
    }
};
