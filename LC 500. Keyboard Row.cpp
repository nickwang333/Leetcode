class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        unordered_map<char, int> m;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(char i:s1){
            m[i] = 1;
        }
        for(char i:s2){
            m[i] = 2;
        }
        for(char i:s3){
            m[i] = 3;
        }
        for(string i:words){
            int d = -1, flag = 1;
            for(char j:i){
                char tmp = tolower(j);
                if(d == -1){
                    d = m[tmp];
                }
                if(d != m[tmp]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                ret.push_back(i);
            }
        }
        return ret;
    }
};
