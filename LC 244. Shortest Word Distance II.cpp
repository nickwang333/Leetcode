class WordDistance {
public:
    map<string, vector<int>> m;
    int n;
    WordDistance(vector<string>& wordsDict) {
        n = wordsDict.size();
        for(int i=0; i<wordsDict.size(); i++){
            m[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int mini = n;
        vector<int> tmpv = m[word2];
        for(int i=0; i<m[word1].size(); i++){
            int tmp = m[word1][i];
            for(int j:tmpv){
                mini = min(mini, abs(j-tmp));
            }
        }
        return mini;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
