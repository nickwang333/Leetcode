class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int tmp1 = -1, tmp2 = -1, ret = wordsDict.size();
        if(word1 != word2){
            for(int i=0; i<wordsDict.size(); i++){
                if(wordsDict[i] == word1){
                    tmp1 = i;
                    if(tmp2 != -1){
                        ret = min(ret, abs(tmp1-tmp2));
                    }
                }
                else if(wordsDict[i] == word2){
                    tmp2 = i;
                    if(tmp1 != -1){
                        ret = min(ret, abs(tmp1-tmp2));
                    }
                }
            }
            return ret;
        }
        else{
            for(int i=0; i<wordsDict.size(); i++){
                if(wordsDict[i] == word1){
                    if(tmp1 == -1){
                        tmp1 = i;
                    }
                    else if(tmp2 == -1){
                        tmp2 = i;
                        ret = min(ret, tmp2-tmp1);
                    }
                    else if(tmp1 > tmp2){
                        tmp2 = i;
                        ret = min(ret, abs(tmp2-tmp1));
                    }
                    else{
                        tmp1 = i;
                        ret = min(ret, abs(tmp2-tmp1));
                    }
                }
            }
        }
        return ret;
    }
};
