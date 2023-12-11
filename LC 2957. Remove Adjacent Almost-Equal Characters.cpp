class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int ret = 0;
        for(int i=1; i<word.size(); i++){
            int diff = abs(word[i] - word[i-1]);
            if(diff <= 1){
                ret++;
                i++;
            }
        }
        return ret;
    }
};
