class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), ret = n*2;
        string tmp = "";
        for(int i=1; i<n; i++){
            if(word[i] > word[i-1]){
                ret -= 3;
            }
        }
        return ret;
    }
};
