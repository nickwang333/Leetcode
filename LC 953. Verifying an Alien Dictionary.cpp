class Solution {
public:
    map<char, int> m;
    bool comp(string s1, string s2){
        int flag = 0;
        for(int i =0; i<min(s1.size(), s2.size()); i++){
            if(m[s1[i]]>m[s2[i]]){
                return false;
            }
            else if(m[s1[i]]<m[s2[i]]){
                return true;
            }
        }
        if(flag == 0 && s1.size() > s2.size()){
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.size(); i++){
            m[order[i]] = i+1;
        }
        for(int i=1; i<words.size(); i++){
            if(!comp(words[i-1], words[i])){
                return false;
            }
        }
        return true;
    }
};
