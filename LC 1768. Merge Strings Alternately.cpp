class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret;
        for(int i=0; i<min(word1.size(), word2.size())*2; i++){
            if(i%2 == 0){
                ret += word1[i/2];
            }
            else{
                ret += word2[i/2];
            }
        }
        if(word1.size() > word2.size()){
            ret += word1.substr(word2.size(), word1.size() - word2.size());
        }
        else{
            ret += word2.substr(word1.size(), word2.size() - word1.size());
        }
        return ret;
    }
};
