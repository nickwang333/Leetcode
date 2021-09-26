class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, int> m;
        for(string i:strs){
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            auto it = m.find(tmp);
            if(it==m.end()){
                m[tmp] = ret.size();
                vector<string> tmp2(0);
                tmp2.push_back(i);
                ret.push_back(tmp2);
            }
            else{
                ret[m[tmp]].push_back(i);
            }
        }
        return ret;
    }
};
