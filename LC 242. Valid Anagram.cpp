class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(char i:s){
            m[i]++;
        }
        for(char j:t){
            m[j]--;
        }
        for(auto it = m.begin(); it != m.end(); it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
