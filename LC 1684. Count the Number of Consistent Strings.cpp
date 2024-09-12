class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<int, int> m;
        int ret = 0;
        for(char i:allowed){
            m[i]++;
        }
        for(string i:words){
            int flag = 1;
            for(char j:i){
                if(m[j] == 0){
                    flag = 0;
                    break;
                }
            }
            ret += flag;
        }
        return ret;
    }
};
