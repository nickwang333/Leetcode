class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ret;
        string tmp;
        for(char i:target){
            string tmp2;
            for(int j=0; j<=i-'a'; j++){
                char c = 'a' + j;
                tmp2 = tmp + c;
                ret.push_back(tmp2);
            }
            tmp = tmp2;
        }
        return ret;
    }
};
