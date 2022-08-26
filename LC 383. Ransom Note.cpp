class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(char i:magazine){
            m[i]++;
        }
        for(char i:ransomNote){
            m[i]--;
            if(m[i]<0){
                return false;
            }
        }
        return true;
    }
};
