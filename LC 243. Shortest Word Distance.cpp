class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int p1 = -1, p2 = -1, ret = wordsDict.size(), counter = 0;
        for(string i:wordsDict){
            if(i == word1){
                if(p2 != -1){
                    ret= min(ret, counter-p2);
                }
                p1 = counter;
            }
            else if(i == word2){
                if(p1 != -1){
                    ret= min(ret, counter-p1);
                }
                p2 = counter;
            }
            counter++;
        }
        return ret;
    }
};
