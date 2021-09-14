class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char, int> m, tmp;
        vector<int> ret;
        for(int i=0; i<p.size(); i++){
            m[p[i]]++;
            tmp[s[i]]++;
        }
        for(int i=p.size()-1; i<s.size(); i++){
            if(i!=p.size()-1){
                tmp[s[i-p.size()]]--;
                tmp[s[i]]++;
            }
            int flag = 0;
            for(auto it = tmp.begin(); it != tmp.end(); it++){
                if(m[it->first] != it->second){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ret.push_back(i-p.size()+1);
            }
        }
        return ret;
    }
};
