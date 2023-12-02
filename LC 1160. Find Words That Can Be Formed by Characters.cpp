class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ret = 0;
        vector<int> charv(26, 0);
        for(auto i:chars){
            charv[i-'a']++;
        }
        for(string i:words){
            vector<int> v(26,0);
            for(char j:i){
                v[j-'a']++;
            }
            int flag = 1;
            for(int j=0; j<26; j++){
                if(v[j] > charv[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                ret += i.size();
            }
        }
        return ret;
    }
};
