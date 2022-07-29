class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        for(string i:words){
            if(i.size() != pattern.size()){
                continue;
            }
            unordered_map<int, int> m1, m2;
            int flag = 0;
            for(int j=0; j<26; j++){
                m1[j] = -1;
                m2[j] = -1;
            }
            for(int j=0; j<i.size(); j++){
                if(m1[i[j]-'a'] == -1 && m2[pattern[j]-'a'] == -1){
                    m1[i[j] - 'a'] =  pattern[j]-'a';
                    m2[pattern[j]-'a'] = i[j]-'a';
                }
                else if((m1[i[j]-'a'] != (pattern[j]-'a')) || (m2[pattern[j]-'a'] != (i[j]-'a'))){
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
